#include<bits/stdc++.h>
using namespace std;

long long n,b,ans1=0,ans2=0,ans3=0,ans=0,t=0;
long long a[10005][10005],c[10005][10005]={0},d[100005],h[100004];

int main()

{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    cin>>n;
    while(n--)
    {
    	cin>>b;
    	for(int i=0,j=0;i<b;j++)
    	{
    		cin>>a[i][j];
    		if(j==3)
    		{
    			i++;
    			j=0;
			}
		}
		
    	for(int i=0;i<b;i++)
    	{
    		if(max(max(a[i][0],a[i][1]),a[i][2])==a[i][0])
	    	{
	    		ans1++;
	    		c[i][0]=1;
	    		d[i]=a[i][0];
			}
			else if(max(max(a[i][0],a[i][1]),a[i][2])==a[i][1])
			{
				ans2++;
				c[i][1]=1;
				d[i]=a[i][1];
			}
			else if(max(max(a[i][0],a[i][1]),a[i][2])==a[i][2])
			{
				ans3++;
				c[i][2]=1;
				d[i]=a[i][2];
			}
			if(ans1>b/2)
			{
				for(int j=0;j<b;j++)
				{
					if(c[j][0]==1)
					{
						h[t]=j;
						t++;
					}
				}
				d[i]
			}
		}
	}
	return 0;
}


