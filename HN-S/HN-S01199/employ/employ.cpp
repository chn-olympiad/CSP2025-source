#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n,m,ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (long long i=n-m+1;i<=n;i++)
		ans=(ans*i)%MOD;
	cout<<ans;
	return 0;
} 
