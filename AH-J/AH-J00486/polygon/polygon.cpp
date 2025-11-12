#include<bits/stdc++.h>
using namespace std;
long long a[100010];
long long n,cnt;
struct stru
{
	long long maxn,sum;
};
vector<stru>v,v2;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	if(n == 3)
	{
		long long maxn = 0,sum = 0;
		for(int i = 1; i <= n; i++)
		{
			maxn = max(maxn,a[i]);
			sum += a[i];
		}
		if(maxn * 2 < sum)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < v.size(); j++)
		{
			if(v[j].maxn != v[j].sum)
			{
				long long sum = v[j].sum + a[i];
				long long maxn = max(v[j].maxn,a[i]);
				if(maxn * 2 < sum)
				{
					v2.push_back({maxn,sum});
					cnt++;
				}
			}
			else
			{
				long long sum = v[j].sum + a[i];
				long long maxn = max(v[j].maxn,a[i]);
				v2.push_back({maxn,sum});
			}
		}
		v2.push_back({a[i],a[i]});
		for(int j = 0; j < v2.size(); j++)
		{
			v.push_back(v2[i]);
		}
		v2.clear();
	}
	cout<<cnt / 2;
	return 0;
}
