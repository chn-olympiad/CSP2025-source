#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n,m,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for (long long i=n-m+1;i<=m;i++)
		ans=(ans*i)%MOD;
	cout<<ans;
	return 0;
}
