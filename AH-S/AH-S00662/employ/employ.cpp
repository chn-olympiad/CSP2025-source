#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353 ;
long long n , m , ans=1 , tmp=1 ;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=m;i++)ans=(ans*i)%MOD;
	tmp=ans;
	for(int i=m;i<=n;i++){
		ans=(ans+(tmp*i)%MOD)%MOD;
	}
	printf("%lld",ans);
	return 0;
}
//MJW保佑我CSPrp++
//MJWYYDS
//CSPrp+++
//苗晋玮保佑我rp++
//rp+=INF
//rp++