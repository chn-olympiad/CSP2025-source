#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
    scanf("%ld",&t);
	int x[1001]={};
	int a[t][1001]={};
	int b[t][1001]={};
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		x[i]=n/2;
		for(int j=0;j<n;j++)
		{
		    int k=0;
			for(;k<t;k++)
			{
	    		cin>>a[j][k];
	    		b[j][k]=a[j][k];
	        	if(a[j][k+1]>a[j][k]&&j!=n-1)
	        	{
	        		swap(b[j][k+1],b[j][k]);
	    		}
			}
			x[i]+=b[j][0];
		}
	}
	for(int i=0;i<t;i++)
	{
		printf("%ld",x[i]);
		cout<<endl;
	}
	return 0;
}
