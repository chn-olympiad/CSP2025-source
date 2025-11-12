#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
const int N=1e5+10;
pii a[N][4];
vector<int> s[4];
int t,n,sum;
int get()
{
	int s1=s[1].size(),s2=s[2].size(),s3=s[3].size();
	if(s1>n/2)
	{
		return 1;
	}
	if(s2>n/2)
	{
		return 2;
	}
	if(s3>n/2)
	{
		return 3;
	}
	return 0;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		sum=0;
		for(int i=1;i<=3;++i)
		{
			s[i].clear();
		}
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=3;++j)
			{
				cin>>a[i][j].fi;
				a[i][j].second=j;
			}
			sort(a[i]+1,a[i]+4,greater<pii>());
			sum+=a[i][1].fi;
			s[a[i][1].se].emplace_back(a[i][1].fi-a[i][2].fi);
//			cout<<a[i][1].se<<"  "<<a[i][1].fi-a[i][2].fi<<"\n";
		}
		int idx=get();
		if(idx)
		{
			int sz=s[idx].size();
			sort(s[idx].begin(),s[idx].end());
			for(int i=0;i<sz-n/2;++i)
			{
//				cout<<s[idx][i]<<"\n";
				sum-=s[idx][i];
			}
		}
		cout<<sum<<"\n";
	}
}
/*

1
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042

125440

*/
