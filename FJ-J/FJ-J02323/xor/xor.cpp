#include <bits/stdc++.h>
using namespace std;
int n,a[500005],s[500005],k,cnt,u,ans;
pair<int,int> p[500005];
bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.second < y.second;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	if(n>100005)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = s[i-1] ^ a[i];
	}
	for(int l = 1; l <= n; l++)
	{
		for(int r = l; r <= n; r++)
		{
			if((s[r]^s[l-1])==k)
			{
				p[++cnt] = {l,r};
	            break;
			}
		}
	}
	sort(p+1,p+cnt+1,cmp);
	for(int i = 1; i <= cnt; i++)
	{
		if(p[i].first>u)
		{
			u = p[i].second;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
