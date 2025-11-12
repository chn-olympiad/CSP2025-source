#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const int S=100005;

int n;
ll a[S][5];
int id[S];

inline void slove()
{
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>a[i][j];
	int ct[5]={0,0,0,0,0};
	ll sm=0;
	for(int i=1;i<=n;i++)
	{
		id[i]=1;
		for(int j=1;j<=3;j++) if(a[i][j]>a[i][id[i]]) id[i]=j;
		sm+=a[i][id[i]];
		ct[id[i]]++;
	}
	for(int x=1;x<=3;x++)
		if(ct[x]>n/2)
		{
			int de=ct[x]-n/2;
			vector<ll> vec;
			for(int i=1;i<=n;i++)
				if(id[i]==x)
				{
					ll mx=0;
					for(int j=1;j<=3;j++) if(j!=x) mx=max(mx,a[i][j]);
					vec.push_back(mx-a[i][x]);
				}
			sort(vec.begin(),vec.end());
			reverse(vec.begin(),vec.end());
			for(int i=0;i<de;i++) sm+=vec[i];
			break;
		}
	cout<<sm<<'\n';
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T-->0) slove();
	return 0;
}
