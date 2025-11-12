#include<bits/stdc++.h>
using namespace std;
long long seat[150];
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int num=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			num++;
			cin>>seat[num];
		}
	}
	int p=seat[1];
	sort(seat+1,seat+num+1,cmp);
	for(int i=1;i<=num;i++)
	{
		if(p==seat[i])
		{
			p=i;
			break;
		}
	}
	int i=1,j=1;
	num=0;
	for(i=1;i<=m;i++)
	{
		for( ; ; )
		{
			
			num++;
			if(num==p)
			{
				cout<<i<<' '<<j;
			}
			if(i%2==0)
			{
				if(j-1<1)
				{
					break;
				}
				j--;
			}
			else
			{
				if(j+1>n)
				{
					break;
				}
				j++;
			}
		}
	}
	return 0;
}