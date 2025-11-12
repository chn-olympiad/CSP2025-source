#include<bits/stdc++.h>
using namespace std;
int n,m,mod=998244353,ans=1,c[505],yh[505][505]={};
string s;
int com(int n,int m){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j==1){
				yh[i][j]==1;
				continue;
			}
			if(i==j){
				yh[i][j]==1;
				continue;
			}
			yh[i][j]=(yh[i-1][j-1]+yh[i][j-1])%mod;
		}
	}
	return yh[n][m];
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	if(n==m){
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				cout<<0<<endl;
				return 0;
			}
		}
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	bool flag=0;
	for(int i=0;i<=n;i++){
		if(s[i]='0')flag=1;
	}
	if(!flag){
		cout<<com(n,m)<<endl;
		return 0; 
	}
}
