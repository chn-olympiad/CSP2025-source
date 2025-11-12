#include<bits/stdc++.h>
using namespace std;
int n,a[100][100],p,q,t,w,s,d,o[100000];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        w=0;
		cin>>n;
		for(int l=1;l<=n;l++)
		for(int m=1;m<=3;m++)
		cin>>a[l][m];
		for(int d=1;d<=n;d++)
		{
		    for(int k=1;k<=n;k++)
		    {
			    if(a[d][k]>a[d][k+1])
			    {
		 	        p=a[d][k];
		 	        a[d][k]=a[d][k+1];
		 	        a[d][k+1]=p;
			        
			    }
		    }
		    w=w+a[d][n+1];
        }
        o[x]=w;
	}
	for(int x=1;x<=t;x++)
	cout<<o[x]<<endl;
	return 0;
}
