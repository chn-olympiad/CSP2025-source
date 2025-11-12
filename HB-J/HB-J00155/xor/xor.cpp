#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,k,a[N];
long long ma=0;
int ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ma=a[i];
		if(ma==k)
		{
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++)
		{
			ma=(ma^a[j]);
			if(ma==k)
			{
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

