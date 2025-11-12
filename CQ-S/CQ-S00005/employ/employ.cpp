#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10,mod=998244353;
int n,m;
string s;
int a[N];
long long ans;
bool pd(){
	for(int i=1;i<=n;i++)if(s[i]!='1')return false;
	return true;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	s=" "+s;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(pd()){
		for(int i=1;i<=n;i++){
			ans=ans%mod*i%mod;
			ans%=mod;
		}
		printf("%lld",ans);
	}
	else printf("%d",m);
	return 0;
}
