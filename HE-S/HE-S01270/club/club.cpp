#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int js=0,s=0,num=0;
	    int jg[5];
	    int n=0,t=0;
	    cin>>t;
	    cin>>n;
	    int a[n-1][3];
	    int r[2];
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<3;j++)
    		{
    			cin>>a[i][j];
    		}
		
    	}
	for(int g=0;g<t;g++)
	{
		num=0;
		for(int h=0;h<n;h++)
		{
			js=a[h][0];
			for(int o=1;o<3;o++)
			{
				if(a[h][o]>js)
				{
					js=a[h][o];
					s=o;
				}
			}
			r[s]+=1;
			num+=js;
		}
		jg[g]=num;
	    cin>>n;
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<3;j++)
    		{
    			cin>>a[i][j];
    		}
		
    	}
	}
	for(int q=0;q<t;q++)
	{
		cout<<jg[q]<<endl;
	}
	return 0;
}
