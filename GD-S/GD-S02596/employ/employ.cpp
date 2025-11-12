#include<bits/stdc++.h>
using namespace std;
int n,m,nandu[510],nai[510],flag1=1,ans=1,vis[510];
/*
int dfs(int dep,int cnt,int fangqi){
	if(dep==n+1){
		if(n==m)ans++;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(nandu[i])dfs(dep+1,cnt)
			if(nai[i]<=s[i-1]+nandu[i])
			//dfs(dep+1,)
		}
	}
}
*/
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;cin>>c;
		nandu[i]=c-'0';
		if(c=='0')flag1=0;
	}
	for(int i=1;i<=n;i++)cin>>nai[i];
	if(m==n){
		int flag=1;
		sort(nai+1,nai+n+1);
		for(int i=1;i<=n;i++){
			if(!nandu[i]||nai[i]==0){
				cout<<0;
				return 0;
			}
		}
		for(int i=1;i<=n;i++){
			ans=(ans*i)%998244353;
		}cout<<ans;
	}
	else if(flag1){
		if(n!=m)cout<<0;
		else{
			for(int i=1;i<=n;i++){
				if(nai[i]==0){
					cout<<0;
					return 0;
				}
				ans=(ans*i)%998244353;
			}
			cout<<ans;
		}
	}
	fclose(stdin);
	fclose(stdout);
} 
