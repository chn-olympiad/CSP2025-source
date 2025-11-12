#include<bits/stdc++.h>
using namespace std;
const long long md=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long n,z=1; cin>>n;
	for(long long x=1;x<=n;x++)
		z=(z*x)%md;
	cout<<z;
	return 0;
}