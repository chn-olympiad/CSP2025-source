//我都双模数了，能不能别卡我
//骗 20pts 容易吗我
//求放过
#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2005,bs=127,mod=998244353,BS=131,MOD=1e9+7;
ull h1[N],h2[N],pr[N],hh1[N],hh2[N];
ull H1[N],H2[N],PR[N],HH1[N],HH2[N];
int n,q,len[N];
char s1[N][N],s2[N][N],ss1[N],ss2[N];
inline ull geths(int l,int r,ull* hash,ull* pr,int mod){
	return (hash[r]-hash[l-1]*pr[r-l+1]%mod+mod)%mod;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1[i]+1,s2[i]+1);
		len[i]=strlen(s1[i]+1);
		for(int j=1;j<=len[i];j++)  h1[i]=(h1[i]*bs+s1[i][j])%mod;
		for(int j=1;j<=len[i];j++)  h2[i]=(h2[i]*bs+s2[i][j])%mod;
		for(int j=1;j<=len[i];j++)  H1[i]=(H1[i]*BS+s1[i][j])%MOD;
		for(int j=1;j<=len[i];j++)  H2[i]=(H2[i]*BS+s2[i][j])%MOD;
	}
	pr[0]=1;for(int i=1;i<=2000;i++)  pr[i]=(pr[i-1]*bs)%mod;
	PR[0]=1;for(int i=1;i<=2000;i++)  PR[i]=(PR[i-1]*BS)%MOD;
	while(q--){
		scanf("%s%s",ss1+1,ss2+1);int l=strlen(ss1+1);
		for(int i=1;i<=l;i++)  hh1[i]=(hh1[i-1]*bs+ss1[i])%mod;
		for(int i=1;i<=l;i++)  hh2[i]=(hh2[i-1]*bs+ss2[i])%mod;
		for(int i=1;i<=l;i++)  HH1[i]=(HH1[i-1]*BS+ss1[i])%MOD;
		for(int i=1;i<=l;i++)  HH2[i]=(HH2[i-1]*BS+ss2[i])%MOD;
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=len[i];j<=l;j++){
				if(geths(j-len[i]+1,j,hh1,pr,mod)==h1[i]
				&&(hh1[l]+(h2[i]-h1[i])*pr[l-j]%mod+mod)%mod==hh2[l]
				&& geths(j-len[i]+1,j,HH1,PR,MOD)==H1[i]
				&&(HH1[l]+(H2[i]-H1[i])*PR[l-j]%MOD+MOD)%MOD==HH2[l])
					++cnt;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
//我不想退役
