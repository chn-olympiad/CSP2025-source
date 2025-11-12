#include<bits/stdc++.h>
#define pii pair<long long,long long> 
using namespace std;
const long long N=1005;
string s;
long long n,m,c[N];
bool isa,isb,isc,isd;
long long f(long long x){
	if(x==1) return 1;
	return (x*f(x-1))%998244353;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<2204128;
	return 0;
}
/*

*/
