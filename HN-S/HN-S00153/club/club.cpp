#include<bits/stdc++.h>
using namespace std;
int n,t;
long long sum[6],a[100005][4],a1,a2,a3,a1m,a2m,a3m,y[100005];
int cz(int x)
{
	for(int i=1;i<=a1m;i++)
	{
		
		for(int j=1;j<=n;j++)
		{
			if(a1==n/2) break;
			if(a[j][1]==a1m && a[j][1]==y[j])
			{
				sum[x]+=a[j][1];
				++a1;
			}
		}
		a1m--;
	}
	for(int i=1;i<=a2m;i++)
	{
		
		for(int j=1;j<=n;j++)
		{
			if(a2==n/2) break;
			if(a[j][2]==a2m && a[j][2]==y[j])
			{
				sum[x]+=a[j][2];
				++a2;
			}
		}
		a2m--;
	}
	for(int i=1;i<=a3m;i++)
	{
		
		for(int j=1;j<=n;j++)
		{
			if(a3==n/2) break;
			if(a[j][3]==a3m && a[j][3]==y[j])
			{
				sum[x]+=a[j][3];
				++a3;
			}
		}
		a3m--;
	}
	return sum[x];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a1m=max(a1m,a[i][1]);
			a2m=max(a2m,a[i][2]);
			a3m=max(a3m,a[i][3]);
			y[i]=max(max(a[i][1],a[i][2]),max(a[i][2],a[i][3]));
		}		
		cz(k);
	}
	for(int i=1;i<=t;i++)
		cout<<sum[i]<<endl;
	return 0;
}
