#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,k;
struct stu
{
	int sc,id;
	bool operator < (const stu &h) const
	{
		return sc>h.sc;
	}
}a[105];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].sc;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m);
	for(int j=1;j<=m;j++)
	{
		if(j%2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[++k].id==1)
				{
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				if(a[++k].id==1)
				{
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
