#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,s,p,c,r,k=1,a[N],ans[15][15];
int compare(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1,compare);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			p=i;
			break;
		}
	}
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(k==p)
				{
					cout<<j<<" "<<i;
					return 0;
				}k++;
			}
		}
		else
		{
			for(int i=n,i2=1;i>=1&&i2<=n;i--,i2++)
			{
				if((j-1)*n+i2==p)
				{
					cout<<j<<" "<<i;
					return 0;;
				}k++;
			}
		}
	}
	return 0;
}