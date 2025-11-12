#include<bits/stdc++.h>
using namespace std;
int work(int n)
{
	int a[205][4];
	int b1[4][205];
	int b2[4][205];
	int b3[4][205];
	int cnt=0;
	int flat[4];
	int mid=n/2;
    for(int i=1;i<=n;i++)
	{
    	cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	if(n==2)
	{
		int sum=0;
		int v[4];
		for(int i=1;i<=3;i++)
		{
			v[i]=max(a[1][i],a[2][i]);
		}
		for(int i=3;i>=2;i--)
    	{
	    	for(int j=1;j<i;j++)
	     	{
	    		if(v[j]<v[j+1])
		    	{
					swap(v[j],v[j+1]);
				}
			}
		}
		for(int i=1;i<=2;i++)
		{
	    	sum=sum+v[i];
		}
	    return sum;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i][1]>a[i][2])
		{
			b1[1][i]=a[i][1];
			b1[3][i]=1;
			b3[1][i]=a[i][2];
			b3[3][i]=2;
			if(a[i][3]>a[i][1])
    		{
	    		b1[1][i]=a[i][3];
	    		b1[3][i]=3;
	    	    b2[1][i]=a[i][1];
	    	    b2[3][i]=1;
    		}
		}
        else if(a[i][1]<a[i][2])
		{
			b1[1][i]=a[i][2];
			b1[3][i]=2;
	    	b2[1][i]=a[i][1];
	    	b2[3][i]=1;
			if(a[i][3]>a[i][2])
    		{
	    		b1[1][i]=a[i][3];
	    		b1[3][i]=3;
			    b3[1][i]=a[i][2];
			    b3[3][i]=2;
    		}
		}
		b1[2][i]=i;
		b2[2][i]=i;
		b3[2][i]=i;
	}
	for(int i=n;i>=2;i--)
	{
		for(int j=1;j<i;j++)
		{
			if(b1[1][j]>b1[1][j+1])
			{
				swap(b1[1][j],b1[1][j+1]);
				swap(b1[2][j],b1[2][j+1]);
				swap(b1[3][j],b1[3][j+1]);
			}
		}
	}
	for(int i=n;i>=2;i--)
	{
		for(int j=1;j<i;j++)
		{
			if(b2[1][j]>b2[1][j+1])
			{
				swap(b2[1][j],b2[1][j+1]);
				swap(b2[2][j],b2[2][j+1]);
				swap(b2[3][j],b2[3][j+1]);
			}
		}
	}
	for(int i=n;i>=2;i--)
	{
		for(int j=1;j<i;j++)
		{
			if(b3[1][j]<b3[1][j+1])
			{
				swap(b3[1][j],b3[1][j+1]);
				swap(b3[2][j],b3[2][j+1]);
				swap(b3[3][j],b3[3][j+1]);
			}
		}
	}
	for(int i=1;i<=n;i++)
    {
        if(flat[1]!=mid)
        {
			if(b1[3][i]==1)
			{
				cnt=cnt+b1[1][i];
				flat[1]++;
			}
            else if(b2[3][i]==1)
            {
				cnt=cnt+b2[1][i];
				flat[1]++;
			}
			else if(b3[3][i]==1)
			{
				cnt=cnt+b3[1][i];
				flat[1]++;
			}
		}
		if(flat[2]!=mid)
        {
			if(b1[3][i]==2)
			{
				cnt=cnt+b1[1][i];
				flat[2]++;
			}
            else if(b2[3][i]==2)
            {
				cnt=cnt+b2[1][i];
				flat[2]++;
			}
			else if(b3[3][i]==2)
			{
				cnt=cnt+b3[1][i];
				flat[2]++;
			}
		}
		if(flat[3]!=mid)
        {
			if(b1[3][i]==3)
			{
				cnt=cnt+b1[1][i];
				flat[3]++;
			}
            else if(b2[3][i]==3)
            {
				cnt=cnt+b2[1][i];
				flat[3]++;
			}
			else if(b3[3][i]==3)
			{
				cnt=cnt+b3[1][i];
				flat[3]++;
			}
		}
	}
	return cnt;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
		int n=0;
		cin>>n;
		cout<<work(n)<<' ';
	}
    return 0;
}
