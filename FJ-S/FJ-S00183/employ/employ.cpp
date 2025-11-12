#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int n,m,a[N],c[N],ans,p[N],bk[N];
char s[N];
void dfs(int step){
	if(step==n+1){
		int now=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(now>=c[p[i]]||a[i]==0)now++;
			else cnt++;
		}
		if(cnt>=m)ans=(ans+1)%mod;
	}
	for(int i=1;i<=n;i++){
		if(bk[i])continue;
		bk[i]=1;
		p[step]=i;
		dfs(step+1);
		bk[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)a[i]=s[i]-'0';
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	if(n<=18)dfs(1);
	printf("%d\n",ans);
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
