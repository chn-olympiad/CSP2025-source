#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[1000][4];
int b[1000];
int sum;
int mx1=-10096,mx2,c[4];
int sam[100],an;
void mmn()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j][i] > mx1)
			{
				mx2=j;
			}
		}
		if(b[mx2]== 0 && c[i] <=n/2-1)
		{
			b[mx2]=i;
			sum+=a[mx2][i];
			c[i]++;
		}
		else if(b[mx2] != 0)
		{
			if(a[mx2][b[mx2]] < a[mx2][i])
			{
				
				sum-=a[mx2][b[mx2]];
				c[b[mx2]]--;
				b[mx2]=i;
				sum+=a[mx2][i];
				c[i]++;
			}
		}
		mx1=-10086;
		mx2=0;
	}
	sam[an]=sum;
	sum=0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		an=i;
		mmn();
	}
	for(int i=1;i<=t;i++)
	{
		cout<<sam[i]<<endl;
	}
	return 0;
}
