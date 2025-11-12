#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=505,Mod=998244353;
int n,m,ans,cr,lu;
int c[N],p[N];	
char s[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(int i=1; i<=n; i++) scanf("%lld",&c[i]);
	if(n<=11){
		for(int i=1; i<=n; i++) p[i]=i;
		do{
			cr=lu=0;
			for(int i=1; i<=n; i++){
				if(cr>=c[p[i]] || s[i]=='0'){
					cr++;
					continue;
				}
				else lu++;
			}
			if(lu>=m) ans++;
		}while(next_permutation(p+1,p+1+n));
		printf("%lld\n",ans);
		return 0;
	}
	else puts("0");
	return 0;
}
