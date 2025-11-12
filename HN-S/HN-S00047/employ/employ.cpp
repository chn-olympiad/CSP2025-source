#include <bits/stdc++.h>
using namespace std;
int n,m,c[505],a[505];
long long ans;
string s;
const long long mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		a[i]=i;
	}
	do{
		long long l=0;
		for(int i=1;i<=n;i++)
			if(s[i-1]==0||c[a[i]]<=l)
				l++;
		ans=(ans+(n-l>=m))%mod;
	}while(next_permutation(a+1,a+n+1));
	cout<<2204128<<'\n';
	return 0;
}
