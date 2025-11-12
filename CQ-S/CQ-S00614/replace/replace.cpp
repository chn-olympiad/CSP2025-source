#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5000002,M=200002,mod=2e9+11;
int n,q,k,sum,xhs[N],yhs[N],pi[N],fac[N],l,r,hs[M][2],ans;
string s[M][2],t1,t2,test;
inline int ksm(int n,int m)
{
	int bas=n,su=1;
	while(m){
		if(m&1) su=su*bas%mod;
		bas=bas*bas%mod,m>>=1;
	}return su;
}
signed main()
{
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	fac[0]=1;for(int i=1;i<N-1;++i) fac[i]=fac[i-1]*26%mod;
	cin>>n>>q;for(int i=1;i<=n;++i){
		cin>>s[i][0]>>s[i][1];
		k=s[i][0].size(),sum=0;
		for(int j=0;j<k;++j){
			sum+=(s[i][0][j]-'a')*fac[j],sum%=mod;
		}hs[i][0]=sum;
		k=s[i][1].size(),sum=0;
		for(int j=0;j<k;++j){
			sum+=(s[i][1][j]-'a')*fac[j],sum%=mod;
		}hs[i][1]=sum;
	}
	for(int i=1;i<=q;++i){
		cin>>t1>>t2,l=t1.size(),r=t2.size();
		if(l!=r){cout<<0<<'\n';continue;}
		sum=0,ans=0;
		for(int j=0;j<l;++j){
			sum+=(t1[j]-'a')*fac[j],sum%=mod;
			xhs[j]=sum;
		}sum=0;
		for(int j=0;j<l;++j){
			sum+=(t2[j]-'a')*fac[j],sum%=mod;
			yhs[j]=sum;
		}for(int j=1;j<=n;++j){
			test=s[j][0]+'#'+t1,k=test.size();
			for(int g=1;g<k;++g){
				int now=pi[g-1];
				while(now&&test[now]!=test[g]) now=pi[now-1];
				pi[g]=now;if(test[now]==test[g]) ++pi[g];
			}int k2=s[j][0].size();
			for(int g=k2+1;g<k;++g){
				if(pi[g]==k2){
					int v=g-k2-1,u=v-k2+1;
					int w=(xhs[l-1]-xhs[v]+(u==0?0:xhs[u-1])+hs[j][1]*fac[u]%mod)%mod;
					if(w==yhs[r-1]) ++ans;
				} 
			}
		}cout<<ans<<'\n';
	}return 0;
}//freopen
//Õ¨ÍêÁË 
