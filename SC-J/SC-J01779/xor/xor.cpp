#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int q[500500],a[500500],ans,l[500500],r[500500],cnt=1;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		q[i]=q[i-1]^a[i];
	}
	int las=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if((q[i]^q[j-1])==k&&l[cnt-1]<j&&r[cnt-1]<j)
			{
				ans++;
				l[cnt]=j,r[cnt]=i;
				cnt++;
			}
		}
	}
	cout<<ans;
	return 0;
 } 