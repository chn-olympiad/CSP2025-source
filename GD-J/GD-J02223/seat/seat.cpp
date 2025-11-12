#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[200],p;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			p=i;
			break;
		}
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cnt++;
			if(cnt==p){
				if(i%2==1) cout<<i<<" "<<j;
				else cout<<i<<" "<<n+1-j;
				break;
			}
		}
	}
	return 0;
}
