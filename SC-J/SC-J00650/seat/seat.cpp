#include<bits/stdc++.h>
using namespace std;
int a[205],n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int l=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*n+j]==l){
				cout<<i<<' ';
				if(i%2) cout<<j;
				else cout<<n-j+1;
				break;
			}
		}
	}
	return 0;
} 