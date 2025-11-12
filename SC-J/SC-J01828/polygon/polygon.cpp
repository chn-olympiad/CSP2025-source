#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,c[1000001],ans;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+n+1);
	for(int i=3;i<=n;i++)
	{
		int mx=INT_MIN,sum=0;
		for(int j=1;j<=i;j++)
		{
			mx=max(mx,c[j]);
			sum+=c[j];
		}
		if(sum>mx*2&&n>=3) cout<<1;
		else cout<<0;
	}
	return 0;
}