#include <bits/stdc++.h>
using namespace std;
int s[12][12],n,m;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int num;
	num=a[0];
	sort(a,a+n*m,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			s[i][j]=a[cnt];
			if(a[cnt]==num)
			{
				cout<<i<<' '<<j;
				return 0;
			}
			cnt++;
		}
	}
    return 0;
}
