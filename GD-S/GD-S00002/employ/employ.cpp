#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510,mod=998244353;
ll n,m,c[N],ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(int i=n;i>=1;i--) ans=ans*i%mod;
	printf("%lld",ans%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
