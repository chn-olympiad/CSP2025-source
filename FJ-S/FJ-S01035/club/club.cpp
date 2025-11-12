#include<bits/stdc++.h>
using namespace std;
int n,t;
int main() 
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		int a[200010][5],sum=0;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2])
			{
				a[i][4]=0;
			}
			if(a[i][0]<a[i][1]&&a[i][1]>a[i][2])
			{
				a[i][4]=1;
			}
			if(a[i][2]>a[i][1]&&a[i][0]<a[i][2])
			{
				a[i][4]=2;
			}
			a[i][3]=max(a[i][1],max(a[i][0],a[i][2]));
		}
		int y=0,e=0,s=0;
		for(int i=1;i<=n;i++)
		{
			
			if(a[i][4]==0)
			{
				y++;
			}
			if(a[i][4]==1)
			{
				e++;
			}
			if(a[i][4]==2)
			{
				s++;
			}
			sum+=a[i][3];/*
			if(y>=n/2)
			{
				
			}*/ 
		}
		cout << sum <<endl;
	}
	return 0;
}
