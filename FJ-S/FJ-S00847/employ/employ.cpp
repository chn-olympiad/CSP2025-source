#include<bits/stdc++.h>
using namespace std;
const int N=505;
int c[N];
const long long MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	unsigned long long ans=1;
	string s;
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=n;i>=1;i--){
		ans=(ans*i);ans=ans%MOD;
	}
	printf("%lld",ans);
	return 0;
}
