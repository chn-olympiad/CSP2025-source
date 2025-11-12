#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
int s[500010];
int cnt[500010];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		s[i]=s[i-1] xor a;
	}
	int p=1;
	for(int r=0;r<=n;r++)
	{
		for(int i=r;i<n;i+=p)
		{
			p=1;
			for (int j=i+1;j<=n;j++)
			{
				int ans=s[i] xor s[j];
				if(ans==k)
				{
					cnt[r]++;
					p=j;
					break;
				}
			}
		}
	}
	int ma=-1;
	for(int i=0;i<=n;i++)
	{
		ma=max(ma,cnt[i]);
	}
	cout<<ma;
	return 0;
}
