#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110],r,se,h,l;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++)
	{
		if(a[i]==r)
		{
			se=i;
			break;
		}
	}
	int sum=1;
	for(int i=1;i<=m;i+=2)
	{
		for(int j=1;j<=n;j++)
		{
			if(sum==se)
			{
				l=i;
				h=j;
				cout<<l<<" "<<h;
				return 0;
			}
			sum++;
		}
		sum+=n;
	}	
	cout<<endl;
	sum=n+1;
	for(int i=2;i<=m;i+=2)
	{
		for(int j=n;j>=1;j--)
		{
			if(sum==se)
			{
				l=i;
				h=j;
				cout<<l<<" "<<h;
				return 0;
			}
			sum++;
		}
		sum+=n;
	}
	return 0;
}
