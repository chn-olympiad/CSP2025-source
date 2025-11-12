#include<bits/stdc++.h>
using namespace std;
int n,m,ans,num,a[20][20],b[400];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>b[i];
		if(i==1) ans=b[i];
	} 
	sort(b+1,b+n*m+1,cmp);
	for(int j=1;j<=m;++j){
		if(j%2==1){
			for(int i=1;i<=n;++i){
				a[i][j]=b[++num];
			}
		}else{
			for(int i=n;i>=1;--i){
				a[i][j]=b[++num];
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]==ans) cout<<j<<" "<<i;
		}
	}
	return 0;
}
