#include <bits/stdc++.h>
using namespace std;
int mian()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,sum=0,s;
    cin>>n>>m;
    sum=n*m;
    int a[sum+5];
    for(int i=1;i<=sum;i++)
    {
        cin>>a[i];
    }
    s=a[1];
    for(int i=1;i<=sum;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(a[j]<a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(int i=1;i<=sum;i++)
    {
        if(a[i]==s)
        {
			s=i;
		}
    }
    for(int i=0;i<sum;i++)
    {
		for(int j=0;j<sum;j++)
		{
			if(s==i*n+j)
			{
				cout<<i+1<<j;
		    }
		}
	}
    return 0;
}
