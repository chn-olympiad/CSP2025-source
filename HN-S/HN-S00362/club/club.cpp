#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a,b,c,cnt[5],sum;
vector<int>v[5];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=0;
		for(int i=1;i<=3;i++)
		{
			cnt[i]=0;
			v[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a>>b>>c;
			int d=max({a,b,c}),e=a+b+c-d-min({a,b,c});
			if(a==d)sum+=a,cnt[1]++,v[1].push_back(d-e);
			else if(b==d)sum+=b,cnt[2]++,v[2].push_back({d-e});
			else sum+=c,cnt[3]++,v[3].push_back(d-e);
		}
		for(int i=1;i<=3;i++)
		{
			if(cnt[i]>n/2)
			{
				sort(v[i].begin(),v[i].end());
				for(int j=0;j<cnt[i]-n/2;j++)sum-=v[i][j];
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}

