#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int N=510;
int n,m,s[N],c[N],p[N];
bool b[N];
char str[N];
ll ans;
void dfs(int i){
	if(i==n+1){
		//for(int j=1;j<=n;j++)
		//	printf("%d ",p[j]);
		//printf("\n");	
		int pre=0,l=0;
		for(int j=1;j<=n;j++){
			int k=p[j];
			if(pre>=c[k]){pre++;continue;}
			if(s[j]==1)l++;else pre++;
		}
		if(l>=m)ans=(ans+1)%mod;
		return;
	}
	for(int j=1;j<=n;j++)
		if(!b[j]){p[i]=j;b[j]=true;dfs(i+1);b[j]=false;}
}
int main() {
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	scanf("%d%d%s",&n,&m,str+1);
	for(int i=1;i<=n;i++)s[i]=str[i]-'0';
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	if(n<=10){dfs(1);printf("%lld",ans%mod);return 0;}
	ll res=1;
	for(int i=1;i<=n;i++)res=(res*i)%mod;
	printf("%lld",res%mod);
	return 0;
}
