//the code is from chenjh
#include<bits/stdc++.h>
#define MAXN 505
using namespace std;
typedef long long LL;
constexpr int mod=998244353;
int n,m;
int c[505];
bool s[MAXN],vis[MAXN];
int fc[MAXN],ans=0,now=0;
void dfs(const int t){
	if(t>n){ans=(ans+(now>=m))%mod;return;}
	if(now+n-t+1<m) return;
//	fprintf(stderr,"%d %d\n",t,now);
	for(int i=1;i<=n;i++)if(!vis[i]){
		vis[i]=1;
		bool fl=(t-1-now)<c[i]&&s[t];
		now+=fl;
//		if(!fl&&t-now>=c[i]) ans=(ans+(now>=m)*fc[n-t])%mod;
//		else
		dfs(t+1);
		now-=fl;
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d ",&n,&m);
	int c1=0;
	for(int i=1;i<=n;i++) s[i]=getchar()^'0',c1+=s[i];
	if(c1<m) return puts("0"),0;
	for(int i=*fc=1;i<=n;i++) scanf("%d",&c[i]),fc[i]=fc[i-1]*i%mod;
	sort(c+1,c+n+1,greater<int>());
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
/*

人杰地灵。 

Ren5Jie4Di4Ling5%

Change:



Idea:

首先可以很容易的想到 O(n!) 的做法。

将 c 排序不会影响答案数量。 

如果将 c 从小到大排序，如果这个人放弃了,那么后面一段的人无论如何都会放弃。

所以从大到小考虑？ 

Command:



*/

