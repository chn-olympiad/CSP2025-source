#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],r;
bool cmp(int a,int b)
{
	if (a>b) return 1;
	else return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=0;
	for (int i=1;i<=m;i++)
	{
		if (i%2==0) sort(a+(1+k*m),a+(1+k*m+n));
		k++;
	}
	for (int i=0;i<m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (a[i*n+j]==r)
			{
				cout<<i+1<<' '<<j;
				return 0;
			}
		}
	}
}