#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y)
{
	return x>y;
}
int n,m,a[11000],num,ax,ay,id,k=0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==num) id=i;
	}
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(flag==0)
		{
			for(int j=1;j<=m;j++)
			{
				k++;
				if(k==id) ax=i,ay=j;
			}
			flag=1;
			continue;
		}
		if(flag==1)
		{
			for(int j=m;j>=1;j--)
			{
				k++;
				if(k==id) ax=i,ay=j;
			}
			flag=0;
			continue;
		}
	}
	cout<<ax<<" "<<ay;
    return 0;
}
