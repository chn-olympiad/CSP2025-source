//GZ-S00269 ×ñÒåÌìÁ¢ ÑîÈó¿­
#include<bits/stdc++.h>
using namespace std;
const int maxn=505,mod=998244353;
long long ans=1;
int n,m;
char c[maxn];
int a[maxn];
void jink(){
	for(int i=1;i<=n;++i)ans=1LL*ans*i%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>(c+1);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	jink();
	printf("%lld\n",ans);
	return 0;
}
