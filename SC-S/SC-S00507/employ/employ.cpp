#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
char str[505];
int c[505],sum[505];
int n,m;
int ans=1;
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(c+1,c+n+1);
	for(int i=0;i<n;i++)
	{
		if(str[i]=='0') sum[i]=sum[i-1]++;
		else if(sum[i-1]>=c[i]) sum[i]=sum[i-1]++;
		else sum[i]=sum[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		for(int j=i-1;j>=1;j--)
		{
			if(sum[j]<c[i]) k=j;
			else break;
		}
		ans*=(i-j);
	}
	cout<<ans;
	return 0;
}