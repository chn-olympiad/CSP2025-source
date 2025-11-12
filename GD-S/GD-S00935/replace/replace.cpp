#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const ll N=200005,M=5000005,jz=19260817,mod1=998244353,mod2=1000000007;
ll sn,qn,ans,l,hx1[N][2],hx2[N][2],len[N],cf1[M],cf2[M],h1[N][2],h2[N][2];
char s[M],s1[M],s2[M];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cf1[0]=cf2[0]=1;
	for(ll i=1;i<M;i++){
		cf1[i]=cf1[i-1]*jz%mod1;
		cf2[i]=cf2[i-1]*jz%mod2;
	}
	scanf("%lld%lld",&sn,&qn);
	for(ll i=1;i<=sn;i++){
		scanf("%s",s+1);
		len[i]=strlen(s+1);
		for(ll j=1;j<=len[i];j++){
			hx1[i][0]=(hx1[i][0]*jz%mod1+s[j])%mod1;
			hx2[i][0]=(hx2[i][0]*jz%mod2+s[j])%mod2;
		}
		scanf("%s",s+1);
		for(ll j=1;j<=len[i];j++){
			hx1[i][1]=(hx1[i][1]*jz%mod1+s[j])%mod1;
			hx2[i][1]=(hx2[i][1]*jz%mod2+s[j])%mod2;
		}
//		printf("[%lld %lld][%lld %lld]\n",hx1[i][0],hx2[i][0],hx1[i][1],hx2[i][1]);
	}
	for(;qn>0;qn--){
		ans=0;
		scanf("%s%s",s1+1,s2+1);
		l=strlen(s1+1);
		for(ll j=1;j<=l;j++){
			h1[j][0]=(h1[j-1][0]*jz%mod1+s1[j])%mod1;
			h2[j][0]=(h2[j-1][0]*jz%mod2+s1[j])%mod2;
		}
		for(ll j=1;j<=l;j++){
			h1[j][1]=(h1[j-1][1]*jz%mod1+s2[j])%mod1;
			h2[j][1]=(h2[j-1][1]*jz%mod2+s2[j])%mod2;
		}
//		printf(" [%lld %lld] [%lld %lld]\n",h1[l][0],h2[l][0],h1[l][1],h2[l][1]);
		for(ll j=1;j<=sn;j++){
			for(ll k=1;k+len[j]-1<=l;k++){
				if((h1[k+len[j]-1][0]-h1[k-1][0]*cf1[len[j]]%mod1+mod1)%mod1==hx1[j][0] && (h1[k+len[j]-1][1]-h1[k-1][1]*cf1[len[j]]%mod1+mod1)%mod1==hx1[j][1]){
					if((h2[k+len[j]-1][0]-h2[k-1][0]*cf2[len[j]]%mod2+mod2)%mod2==hx2[j][0] && (h2[k+len[j]-1][1]-h2[k-1][1]*cf2[len[j]]%mod2+mod2)%mod2==hx2[j][1]){
						if((h1[l][0]-hx1[j][0]*cf1[l-len[j]-k+1]%mod1+hx1[j][1]*cf1[l-len[j]-k+1]%mod1+mod1)%mod1==h1[l][1]){
							if((h2[l][0]-hx2[j][0]*cf2[l-len[j]-k+1]%mod2+hx2[j][1]*cf2[l-len[j]-k+1]%mod2+mod2)%mod2==h2[l][1]){
								ans++;
//								printf("{%lld %lld}\n",j,k);
								break;
							}
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
