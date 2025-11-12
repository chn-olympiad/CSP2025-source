#include<bits/stdc++.h>
#define FL(i,a,b) for(int i=(a);i<=(b);i++)
#define FR(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
#define ull unsigned long long
#define ld long double
#define PII pair<ll,ll> 
using namespace std;
const int MAXN = 2e5 + 10;
const int P = 929;
const int Mod = 1e9 + 9;

int n,q,len;
char s1[MAXN],s2[MAXN];
ll hsh1[MAXN],hsh2[MAXN],pw[MAXN];
vector<PII>E[MAXN];

ll Get1(int l,int r){
	return (hsh1[r]-hsh1[l-1]*pw[r-l+1]%Mod+Mod)%Mod;
}
ll Get2(int l,int r){
	return (hsh2[r]-hsh2[l-1]*pw[r-l+1]%Mod+Mod)%Mod;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	pw[0]=1;
	FL(i,1,MAXN-1) pw[i]=pw[i-1]*P%Mod;
	FL(j,1,n){
		scanf("%s",s1+1),len=strlen(s1+1);
		scanf("%s",s2+1);
		ll val1=0,val2=0;
		FL(i,1,len) val1=(val1*P%Mod+(ll)(s1[i]-'a'+1))%Mod;
		FL(i,1,len) val2=(val2*P%Mod+(ll)(s2[i]-'a'+1))%Mod;
		E[len].push_back({val1,val2});
//		printf("%lld %lld\n",val1,val2);
	}
	FL(j,1,q){
		ll res=0;
		scanf("%s",s1+1),len=strlen(s1+1);
		scanf("%s",s2+1);
		if(strlen(s2+1)!=len){
			puts("0");
			continue;
		}
		int L=0,R=0;
		FL(i,1,len){
			if(s1[i]!=s2[i]){
				L=i;
				break;
			}
		}
		FR(i,len,1){
			if(s1[i]!=s2[i]){
				R=i;
				break;
			}
		}
		hsh1[0]=hsh2[0]=0;
		FL(i,1,len) hsh1[i]=(hsh1[i-1]*P%Mod+(ll)(s1[i]-'a'+1))%Mod; 
		FL(i,1,len) hsh2[i]=(hsh2[i-1]*P%Mod+(ll)(s2[i]-'a'+1))%Mod; 
		if(!L&&!R){
			FL(Len,2,len){
				FL(l,1,len-Len+1){
					int r=l+Len-1;
					ll h1=Get1(l,r),h2=Get2(l,r);
					for(auto i:E[Len])
						if(h1==i.first&&h2==i.second) res++;
				}
			}
		}
		else{
			FR(l,L,1){
				FL(r,R,len){
					int Len=r-l+1;
//					printf("%d %d\n",l,r);
					ll h1=Get1(l,r),h2=Get2(l,r);
//					printf("%lld %lld\n",h1,h2);
					for(auto i:E[Len])
						if(h1==i.first&&h2==i.second) res++;
				}
			}
		}
		printf("%lld\n",res);
	}
}
