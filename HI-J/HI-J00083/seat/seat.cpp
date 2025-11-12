#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[15][15];
	int b[105];
	int n,m;
	int i,j,c;
	int x,y;
	int w;
	
	cin>>n>>m;
	for(int q=1;q<=n*m;q++)
	{
		cin>>b[q];
	}
	w=b[1];
	//·ÖÊý 
	/*for(int p=1;p<=n*m;p++)
	{
		if()
	}*/
	/*
	for(j=1;j<n;j++)
	{
		//int d=j;
		for(c=n*m;c>1;c--)
		{
			if(j%2==1)
		    {
			    for(i=1;i<n;i++)
	            {
		            a[i][j]=b[c];
	            }
	        }
		    if(j%2==0)
		    {
			    for(i=n;i>1;i--)
			    {
			    	a[i][j]=b[c];
			    }
		    }
		    if(b[c]=w)
		    {
		    	x=i;y=j;
			}
		}
	}
	*/
	cout<<n<<m;
	
	return 0;
}
