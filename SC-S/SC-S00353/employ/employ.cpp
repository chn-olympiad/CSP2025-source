#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) x&-x
const int N=500+5;
const int mod=998244353;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar(); 
	}
	return x*f;
}
char s[N];
int n,m,c[N],sum[N];
int nd[N];
ll ans;
bool flags=true,vis[N];
bool ch(int n){
	int tot=0,mot=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') mot++;
		else{
			if(mot>=c[nd[i]]) mot++;
			else tot++;
		}
		if(mot>n-m) return false;
		if(tot>=m) return true;
	}
	return tot>=m;
}
void dfs(int x){
	if(x==n){
		if(ch(n))ans++,ans%=mod;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		nd[x+1]=i;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)c[i]=read(),vis[i]=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			flags=false;
			break;
		}
	}
	sort(c+1,c+n+1);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1];
	} 
	if(m==n){
		if(flags && c[1]!=0){
			ans=1;
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=mod;
			}
		}
		else ans=0;
		printf("%lld\n",ans);
	}
	else if(flags && c[1]!=0){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
	else if(m==1){
		if(s[1]=='1'){
			ans=1;
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=mod;
			}
		}
		printf("%lld\n",ans);
	}
	else{
		dfs(0);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/