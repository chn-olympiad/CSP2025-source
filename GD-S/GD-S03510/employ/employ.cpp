#include<bits/stdc++.h>
using namespace std;
const int N =1e6+10;
const int mod=998244353;
#define int long long 
int n,m,ans,a[N],c[N],vis[N];
char s[N];
void calc(){
	int now=0,pass=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')	now++;
		else if(now>=c[a[i]])	now++;
		else pass++;
	} 
	if(pass>=m)	ans++;
	ans%=mod;
} 
void dfs(int now){
	if(now==n+1){
		calc();
		return ;
	}
	
	for(int i=1;i<=n;i++){
		if(vis[i])	continue;
		
		a[now]=i,vis[i]=1,dfs(now+1),a[now]=0,vis[i]=0; 
	}
}
void Slove(){
	for(int i=1;i<=n;i++){
		if(s[i]=='0'||c[i]==0)	cout<<0<<endl,exit(0);
	}
	ans=1;
	for(int i=1;i<=n;i++)	ans*=i,ans%=mod; 
	cout<<ans<<endl;
} 
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)	cin>>c[i];
	if(n<=10)	dfs(1),cout<<ans<<endl,exit(0);
	Slove();
	return 0;
}
/*
3 1 
101
1 1 2
*/

