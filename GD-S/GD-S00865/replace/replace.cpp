#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200005
#define M 5000005
ll n,q,hsh1[N][2],hsh2[N][2],hsh3[M][2],hsh4[M][2];
char s[M],s1[M],t1[M];
const ll mod1=998244353;
const ll mod2=1000000009;
const ll bs1=462377;
const ll bs2=2831789;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(ll i=1;i<=n;i++){
		scanf("%s",s+1);
		ll len=strlen(s+1);
		for(ll j=1;j<=len;j++){
			hsh1[i][0]=(hsh1[i][0]*bs1+(s[j]-'a'+1))%mod1;
			hsh1[i][1]=(hsh1[i][1]*bs2+(s[j]-'a'+1))%mod2;
		}
		scanf("%s",s+1);
		for(ll j=1;j<=len;j++){
			hsh2[i][0]=(hsh2[i][0]*bs1+(s[j]-'a'+1))%mod1;
			hsh2[i][1]=(hsh2[i][1]*bs2+(s[j]-'a'+1))%mod2;
		}
	}
	while(q--){
		scanf("%s%s",s1+1,t1+1);
		ll len=strlen(s1+1),len1=strlen(t1+1),pos1=0,pos2=0;
		if(len!=len1){printf("0\n");continue;}
		for(ll i=1;i<=len;i++){
			hsh3[i][0]=(hsh3[i-1][0]*bs1+(s1[i]-'a'+1))%mod1;
			hsh4[i][0]=(hsh4[i-1][0]*bs1+(t1[i]-'a'+1))%mod1;
			hsh3[i][1]=(hsh3[i-1][1]*bs2+(s1[i]-'a'+1))%mod2;
			hsh4[i][1]=(hsh4[i-1][1]*bs2+(t1[i]-'a'+1))%mod2;
			if(s1[i]!=t1[i]){
				if(!pos1) pos1=i;
				pos2=i;
			}
		}
		printf("0\n");
	}
	return 0;
}
/*
4 2
xabcx xadex
aa bb
ab cd
bc de
xabcx xadex
aaaa bbbb 
*/
