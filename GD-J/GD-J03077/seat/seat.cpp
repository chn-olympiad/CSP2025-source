#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100]={0};
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n*m-1;i++)
	{
		for(int j=i+1;j<n*m;j++)
		{
			if(a[i]<a[j])
			{
				int z=a[i];
				a[i]=a[j];
				a[j]=z;
			}
		}
	}
	int x=0,y=0;
	int z=1;
	bool flag=false;
	while(1)
	{
		for(int i=0;i<n;i++)
		{
			if(a[0]<a[z])
			{
				x+=1;
			}
			else
			{
				flag=true;
				break;
			}
			z++;
		}
		if(flag) break;
		x-=1;
		y+=1;
		for(int i=0;i<n;i++)
		{
			if(a[0]<a[z])
			{
				x-=1;
			}
			else
			{
				flag=true;
				break;
			}
			z++;
		}
		if(flag) break;
		x+=1;
		y+=1;
	}
	cout<<y+1<<" "<<x+1;
	return 0;
}
