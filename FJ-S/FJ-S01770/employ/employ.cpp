#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
bool vis[505];
long long ans,mod=998244353,jie[505];
void dfs(int now,int ed){
	if(ed==m&&now<=n+1){
		//cout<<"*";
		//cout<<now-1<<ed<<jie[n-now+1]<<endl;
		ans=(ans+jie[n-now+1])%mod;
		//ans++;
		return;
	}
	if(now>n)return;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			//cout<<i;
			if(c[i]>now-ed-1){
				//cout<<i;
				vis[i]=1;
				if(s[now-1]=='1')dfs(now+1,ed+1);
				else dfs(now+1,ed);
				vis[i]=0;
			}else{
				vis[i]=1;
				//if(s[now-1]=='1')dfs(now+1,ed+1);
				dfs(now+1,ed);
				vis[i]=0;
			}
		}
	}
	//return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	jie[0]=1;
	for(int i=1;i<=n+1;i++){
		jie[i]=(jie[i-1]*i)%mod;
	}
	//cout<<jie[3];
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1,0);
	cout<<ans;
	return 0;
} 
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
