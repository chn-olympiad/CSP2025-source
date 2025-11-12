#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int n,m,a[105],f[15][15],s,cnt;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)s=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=a[++cnt];
			if(s==a[cnt])
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
		i++;
		if(i>m)break;
		for(int j=n;j>=1;j--)
		{
			f[i][j]=a[++cnt];
			if(s==a[cnt])
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
