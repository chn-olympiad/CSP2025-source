#include<bits/stdc++.h>
using namespace std;
int n,m,c[100005],ans;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int j=m;j<=n-1;j++)
	{
		long long res=1;
		for(int i=n;i>=n-j;i--)
		{
			res=res*i%998244353;
			res%=998244353;
		}
		ans+=res;
	}
	cout<<ans;
	return 0;
}


