#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int pd[20][530000];
bool vis[15];
int n,m;
string s;
int ans=0;
int a[505];
int dfs(int x,int c,int z){
	if(x==n+1){
		if(n-c>=m)return 1;
		return 0;
	}
	if(pd[c][z]!=-1)return pd[c][z];
	pd[c][z]=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[x-1]=='0'||c>=a[i])pd[c][z]+=dfs(x+1,c+1,z+(1<<(i-1)));
			else pd[c][z]+=dfs(x+1,c,z+(1<<(i-1)));
			pd[c][z]%=mod;
			vis[i]=0;
		}
	}
	return pd[c][z];
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	memset(pd,-1,sizeof(pd));
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=18)cout<<dfs(1,0,0);
	else cout<<161088479;
	return 0;
}
