#include<bits/stdc++.h>
#define P 998244353
using namespace std;
int a[505];
long long f(int n)
{
	int ans=1;
	for(int i=1;i<=n;++i)
		ans=((ans+P)%P)*i%P;
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	cout<<f(n)<<"\n";
	return 0;
}
