#include<bits/stdc++.h>
using namespace std;

int cmp(int temp,int a[],int n,int o,int g,int f,int m)
{
    int sum=0;
	if(temp==o)
	{
		for(int j=f+1;j<n;j++)
		{
			int y=0;
			y=max(m,a[j]);
			if((g+a[j])>(2*y))
			{
				sum++;
			}
		}
		return sum;
	}
	else
	{
		for(int j=f+1;j<n-o+temp;j++)
		{
			int y=0;
			y=max(m,a[j]);
			sum+=cmp(temp+1,a,n,o,g+=a[j],f+1,y);
		}
		return sum;
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0;
	int a[5001]={0};
	cin>>n;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		ans+=cmp(1,a,n,i,0,0,0);
	}
	cout<<ans+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
