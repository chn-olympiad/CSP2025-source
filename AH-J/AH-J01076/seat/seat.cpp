#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[15][15],b[110];
bool cmp(const LL &x,const LL &y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	LL n,m;
	cin>>n>>m;
	for(LL i=1;i<=n;i++)
	{
		for(LL j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	LL s=a[1][1],t=1;
	for(LL i=1;i<=n;i++)
	{
		for(LL j=1;j<=m;j++)
		{
			b[t]=a[i][j];
			t++;
		}
	}
	sort(b+1,b+1+t,cmp);
	LL tt=1;
	for(LL i=1;i<=n;i++)
	{
		if(i%2!=0)
		{
			for(LL j=1;j<=m;j++)
			{
				if(b[tt]==s)
				{
					cout<<i<<" "<<j;
				}
				tt++;
			}
		}
		else
		{
			for(LL j=m;j>=1;j--)
			{
				if(b[tt]==s)
				{
					cout<<i<<" "<<j;
				}
				tt++;
			}
		}
	}
	return 0;
}
