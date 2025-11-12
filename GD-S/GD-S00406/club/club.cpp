#include <bits/stdc++.h>

using namespace std;
long long T;
struct ad{
	int fi,se;
};
bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.first>y.first;
}
bool cmp1(ad q,ad w)
{
	return q.fi>w.fi;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ad a[100005],b[100005];
		vector<vector<int>> d(100005),e(100005);
		long long n,ans=0,ans2=0,book[1000005];
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			pair<int,int> w[8];
			for(int j=1;j<=3;j++)
			{
				cin>>w[j].first;
				w[j].second=j;
			}
			sort(w+1,w+4,cmp);
			a[i].fi=w[1].first,a[i].se=w[1].second;
			b[i].fi=w[2].first,b[i].se=w[2].second;
		}
		sort(a+1,a+1+n,cmp1);
		sort(b+1,b+1+n,cmp1);
		for(int i=1;i<=n;i++)
		{
			if(d[a[i].se].size()<n/2){d[a[i].se].push_back(a[i].fi);}
			else {d[b[i].se].push_back(b[i-n/2].fi);}
		}
		for(int i=1;i<=n;i++)
		{
			if(e[b[i].se].size()<n/2){e[b[i].se].push_back(b[i].fi);}
			else {e[a[i].se].push_back(a[i-n/2].fi);}
		}
		for(int i=1;i<=3;i++)
		{
			for(auto j:d[i])
			{
				ans+=j;
			}
		}
		for(int i=1;i<=3;i++)
		{
			for(auto j:e[i])
			{
				ans2+=j;
			}
		}
		cout<<max(ans,ans2)<<'\n';
	}
	
	return 0;
} 

