#include<bits/stdc++.h>
using namespace std;
int li[105][105],a[1000],cnt,n,m,b,x=1,y=1,shu;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cnt++;
			cin>>a[cnt];
		}
	}
	b=a[1];
	sort(a,a+cnt+1);
	while(cnt>0)
	{
		for(int i=1;i<=n;i++)
		{

			li[i][y]=a[cnt];
			if(b==a[cnt])
			{
				cout<<y<<" "<<i;
				return 0;
			}
			cnt--;
		}
		y++;
		for(int i=n;i>=1;i--)
		{
			li[i][y]=a[cnt];
			if(b==a[cnt])
			{
				cout<<y<<" "<<i;
				return 0;
			}
			cnt--;
		}
		y++;
	}
	return 0;
}
