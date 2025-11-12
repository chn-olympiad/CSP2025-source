#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,mod=998244353;
int c[N];
int cnt[N];
int jc[N];
int n,m,fl[N];
int ans=0;
string s;
void dfs(int ss,int ct){
	if(ss>n)
		return ;
	for(int i=1;i<=n;i++){
		if(fl[i]==1) continue;
		int g=0;
		if(s[ss]=='1' && c[i]>ss-ct-1) g=1;
		if(ct+g>=m){
			(ans+=jc[n-ss])%=mod;
			continue;
		}
		fl[i]=1;
		dfs(ss+1,ct+g);
		fl[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
	cin>>s;s='*'+s;
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	bool fl=true;
	for(int i=1;i<=n;i++) if(s[i]=='1') fl=false;
	if(fl){
		printf("0\n");
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++) cnt[c[i]]++;
		for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
		int ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		int sum=1,ct=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				sum=sum*(cnt[i-1]-ct)%mod;
				ct++;
			}
		}
		for(int i=1;i<=n-ct;i++) sum=sum*i%mod;
		printf("%lld",(ans-sum+mod)%mod);
		return 0;
	}else if(m==n){
		bool fl=true;
		for(int i=1;i<=n;i++) if(s[i]=='0' || c[i]==0) fl=false;
		if(fl){
			int ans=1;
			for(int i=1;i<=n;i++) ans=ans*i%mod;
			printf("%lld\n",ans);
		}else printf("0\n");
		return 0;
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}