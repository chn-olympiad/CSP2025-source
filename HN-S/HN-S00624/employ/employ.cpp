/* ChongYun */
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=505,mod=998244353;
int n,m,lim[N],ans=0;
char s[N];
int flg[N],p[N];
void dfs(int x){
	if(x==n+1){
		int now=0,num=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='1'&&now<lim[p[i]]) ++num;
			else ++now; 
		}
		if(num>=m) ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;++i){
		if(flg[i]) continue;
		flg[i]=1,p[x]=i;
		dfs(x+1);
		flg[i]=0,p[x]=0;
	}
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	int flg=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='0') flg=1;
	}
	int cnt=0;
	for(int i=1;i<=n;++i) lim[i]=read(),cnt+=(lim[i]==0);
	dfs(1);
	printf("%lld\n",ans); 
	return 0;
} 
