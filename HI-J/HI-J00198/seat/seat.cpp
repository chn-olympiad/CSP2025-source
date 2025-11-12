#include<bits/stdc++.h>
using namespace std;
long long a[105];
long long zw[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	long long s=a[1];
	sort(a+1,a+n*m+1);
	long long a1=0,b1=1,x[3]={1,-1,0},y[3]={0,0,1};
	for(long long i=n*m;i>=1;i--)
	{
		for(long long j=0;j<3;j++)
		{
			if(a1+x[j]<=n&&a1+x[j]>=1&&b1+y[j]<=m&&b1+y[j]>=1&&zw[a1+x[j]][b1+y[j]]==0)
			{
				a1+=x[j];
				b1+=y[j];
				zw[a1][b1]=a[i];
				if(zw[a1][b1]==s)
				{
					cout<<b1<<" "<<a1;
				}
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
