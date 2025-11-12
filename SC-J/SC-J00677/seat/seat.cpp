#include <bits/stdc++.h>
using namespace std;

const int N=1e2+10;

struct NODE
{
	int idx,sum;

	bool operator< (const NODE &b) const
	{
		return sum>b.sum;
	}
};

int n,m,cnt=0;
NODE a[N];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].sum;
		a[i].idx=i;
	}
	sort(a+1,a+n*m+1);
	for(int j=1;j<=m;j++)
	{
		if(j%2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[++cnt].idx==1)
				{
					cout<<j<<" "<<i;
					break;
				}
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				if(a[++cnt].idx==1)
				{
					cout<<j<<" "<<i;
					break;
				}
			}
		}
	}
	return 0;
}