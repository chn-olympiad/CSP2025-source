#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int>a(n+10);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	vector<pii>q;
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=i;j<=n;j++)
		{
			sum^=a[j];
			if(sum==k)
			{
				q.push_back({j,i});
				break;
			}
		}
	}
	sort(q.begin(),q.end());
	int maxr=0,ans=0;
	for(int i=0;i<q.size();i++)
	{
		int l=q[i].second,r=q[i].first;
		if(l>maxr)
		{
			ans++;
			maxr=r;
		}
	}
	cout<<ans;
	return 0;
}