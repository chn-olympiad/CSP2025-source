#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,mod=998244353,c[505],p[505],k[505],ans=1;
char s[505];
int main(){
	/*freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);*/
	scanf("%lld%lld",&n,&m);
	scanf("%s",s);
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		p[i]=p[i-1]+1-s[i-1]+'0';
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(p[j]<c[i]) k[j]++;
		}
	}
	for(int i=1;i<=n;i++){
		ans=ans*(k[i]-i+1)%mod;
		printf("%lld\n",k[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
//²ÝÉñµÄÐÅÍ½+1 Q-Q 
