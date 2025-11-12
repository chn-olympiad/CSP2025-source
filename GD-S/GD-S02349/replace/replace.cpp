#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q;
char s1[110][210],s2[110][210];
char fr[210],to[210];
char cp[210];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(ll i=1;i<=n;i++) scanf("%s%s",s1[i]+1,s2[i]+1);
	while(q--){
		ll ans=0;
		scanf("%s%s",fr+1,to+1);
		ll len=strlen(fr+1);
		for(ll i=1;i<=len;i++){
			for(ll j=1;j<=n;j++){
				ll lem=strlen(s1[j]+1);
				if(lem>i) continue;
				ll pos1=i-lem+1,pos2=1;
				bool f=true;
				for(ll k=1;k<pos1;k++){
					if(fr[k]!=to[k]){
						f=false;
						break;
					}
				}
				if(!f) continue;
				for(ll k=i+1;k<=len;k++){
					if(fr[k]!=to[k]){
						f=false;
						break;
					}
				}
				if(!f) continue;
				while(pos1<=i&&pos2<=lem&&fr[pos1]==s1[j][pos2]&&to[pos1]==s2[j][pos2])  pos1++,pos2++;
				if(pos2<=lem) continue;
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
