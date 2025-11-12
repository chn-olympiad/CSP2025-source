#include<bits/stdc++.h>
using namespace std;
const int N=103;
int a[N],n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+n*m);
	int p=0;
	for(int i=n*m;i>=1;i--)
	{
		p++;
		if(a[i]==t)break;
	}
	int c=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c++;
			if(c==p)
			{
				if(i%2==1)
				{
					cout<<i<<' '<<j;
				}
				else
				{
					cout<<i<<' '<<n-j+1;
				}
				break;
			}
		}
	}
	return 0;
}