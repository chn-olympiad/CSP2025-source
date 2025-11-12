#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][10],b,num=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int z=0;z<t;z++)
	{
		cin>>n;
	    for(int i=0;i<n;i++)
	    {
	    	b=0;
		    for(int j=0;j<3;j++)
		    {
			    cin>>a[i][j];
			    if(b<a[i][j])
			    {
			    	b=a[i][j];
				}
		    }
		    num+=b;
	    }
    }
	return 0;
}
