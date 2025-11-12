#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m,ans,c[N],a[N];
char s[510];
bool vis[N];
bool count(){
	int sum=0,num=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') sum++;
		else if(sum>=c[a[i]]) sum++;
		else num++;
	}
	return num>=m;
}
void dfs(int x){
	if(x>n){
		ans=(ans+count())%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		a[x]=i;
		vis[i]=true;
		dfs(x+1);
		a[x]=vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(n<=18){
		dfs(1);
		printf("%d\n",ans); 
	}else{
		long long ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
