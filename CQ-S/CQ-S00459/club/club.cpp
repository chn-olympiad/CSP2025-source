#include<bits/stdc++.h>
#define int long long
#define File(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;
int t;
signed main()
{
	File("club");
	ios::sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while(t--)
	{
		vector<int>v[3];
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			int mx=max({a,b,c});
			if(mx==a)
				v[0].emplace_back(min(a-b,a-c));
			else if(mx==b)
				v[1].emplace_back(min(b-a,b-c));
			else if(mx==c)
				v[2].emplace_back(min(c-a,c-b));
			ans+=mx;
		}
		n>>=1;
		int siz0=v[0].size(),siz1=v[1].size(),siz2=v[2].size(),id=0;
		sort(v[0].begin(),v[0].end());
		while(siz0>n)
		{
			ans-=v[0][id];
			siz0--;
			id++;
		}
		sort(v[1].begin(),v[1].end());
		while(siz1>n)
		{
			ans-=v[1][id];
			siz1--;
			id++;
		}
		sort(v[2].begin(),v[2].end());
		while(siz2>n)
		{
			ans-=v[2][id];
			siz2--;
			id++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
考虑直接贪心
先直接每个放最高的 
然后只会存在一种多余1/2
把那种按 最大-次大排序
然后减去对应的权值
应该是对的
开写 
14:38 
AC
14:47
*/
