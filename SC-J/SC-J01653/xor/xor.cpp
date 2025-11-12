#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int num[N];
int xo[N];
int cnt;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		xo[i]=num[i];
	}
	for(int i=1;i<=n;i++)
		xo[i]^=xo[i-1];
	int minn=n+1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt>1e8)
		{
			cout<<0;
			return 0;
		}
		if(i<=minn)
		{
			for(int j=i;j<=minn;j++)
			{
				cnt++;
				if((xo[j]^xo[i-1])==k)
				{
					minn=j;
					break;
				}
			} 
		}
		else
		{
			ans++;
			minn=n+1;
			i--;
		}
	}
	if(minn==n)
		ans++;
	cout<<ans;
	return 0;
} 