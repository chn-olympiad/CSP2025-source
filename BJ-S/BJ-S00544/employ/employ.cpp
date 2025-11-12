#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
int n,m,c[1000],cnt;
ll ans=1;
char s[1000];
int main(){
	freopen("employ3.in","r",stdin);
	// freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
		if(c[i]!=0)cnt++;
	}
	for(int i=1;i<=n;i++)ans=ans*i%mod;
	printf("%lld",ans);
	return 0;
}