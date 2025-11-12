#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;
int n,m,a[100010],score;
int p[114][114],sum=1;
bool cmp(int i,int j)
{
	return i>j;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int al=n*m;
	for(int i=1;i<=al;i++)
		cin>>a[i];
	score=a[1];
	sort(a+1,a+al+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
			for(int j=1;j<=n;j++)
			{
				p[j][i]=a[sum];
				if(a[sum]==score)
				{
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				sum++;
			}
		else
			for(int j=n;j>=1;j--)
			{
				p[j][i]=a[sum];
				if(a[sum]==score)
				{
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				sum++;
			}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<p[i][j]<<" ";
		cout<<endl;
	}*/
	return 0;
}
