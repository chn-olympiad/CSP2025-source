#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
	int x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1),x+=(c-48),c=getchar();
	return x;
}
const int maxn=505,mod=998244353;
int ht[maxn],n,m,ans=0;
bitset<maxn> mp,mmp;
void dfs(int x,int go){
	if(x>n || go>n-m){
		if(go<=n-m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!mmp[i]){
			mmp[i]=true;
			if(!mp[x] || go>=ht[i]) dfs(x+1,go+1);
			else dfs(x+1,go);
			mmp[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int x=0,count=0;
	n=read(),m=read();
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		mp[++x]=c-'0';
		c=getchar();
	}
	for(int i=1;i<=n;i++) ht[i]=read(),count+=(ht[i]!=0);
	if(mp.count() == n){
		ll ans=1;
		for(int i=1;i<=count;i++) ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
} 
