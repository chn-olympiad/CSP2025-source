#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,c[505],a[505],ans;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
		a[i]^=1;
		a[i]+=a[i-1];
	}
	do
	{
		long long cnt=0;
		for (int i=1;i<=n;i++)
		{
			if (c[i]>=a[i-1]&&a[i]-a[i-1]==0) cnt++;
		}
		if (cnt>=m) ans++;
	}
	while(next_permutation(c+1,c+1+n));
	cout<<ans;
	return 0;
}
