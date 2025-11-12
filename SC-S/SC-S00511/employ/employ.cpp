#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=505;
int n,m,sum,ans,dfn[N],pass,Can[N],jc[N],a[N];
char s[N];
void init(){
	jc[0]=1;
	for(int i=1;i<=500;i++)
		jc[i]=jc[i-1]*i%mod;
}
void dfs(int step){
	if(Can[step]+pass<m)
		return;
	if(step==n+1){
		ans++;
		return;
	}
	if(Can[step]==0){
		(ans+=jc[n-step+1])%=mod;
		return;
	}
	for(int i=1;i<=n-step+1;i++){
		int x=dfn[i];
		bool cmp=(a[x]>step-pass-1)&&(s[step]=='1');
		swap(dfn[i],dfn[n-step+1]);
		if(cmp)
			pass++;
		dfs(step+1);
		if(cmp)
			pass--;
		swap(dfn[i],dfn[n-step+1]);
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();
	scanf("%lld%lld%s",&n,&m,s+1);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
		sum+=s[i]-'0';
	if(sum<m){
		printf("0\n");
		return 0;
	}
	if(m==n)
		printf("%lld\n",jc[n]);
	if(n<=18){
		for(int i=1;i<=n;i++)
			dfn[i]=i;
		for(int i=n;i>=1;i--)
			Can[i]=Can[i+1]+(s[i]-'0');
		dfs(1);
		printf("%lld\n",ans%mod);
		return 0;
	}
	printf("%lld\n",jc[n]);
	return 0;
}