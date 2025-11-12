#include<bits/stdc++.h>
using namespace std;
int n,m;
struct kk{
	int x,bh;
}a[110];
bool cmp(kk i,kk j){
	return i.x>j.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].bh=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].bh==1){
			int k=(i-1)/n+1,l=(i-1)%n+1;
			cout<<k<<" ";
			if(k%2==1){
				cout<<l;
			}
			else cout<<n-l+1;
			break;
		}
	}
	return 0;
} 
