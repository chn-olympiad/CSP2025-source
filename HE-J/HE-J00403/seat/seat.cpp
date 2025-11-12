#include<bits/stdc++.h> 
using namespace std;
int y[1001];
int oo[1001];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r=0;
	int k=1;
	int a[n][m];
	cin>>n>>m;
	for(int i=1;i<n*m;i++)
	{
		cin>>y[i];
	}
	for(int i=0;i<=n*m;i++)
	{
		for(int j=1;j<i;i++)
    	{
            if(y[i]<y[i+1])
            {
            	oo[i]=y[i];
                y[i]=oo[i+1];
                y[i]=oo[i];
        	}
			if(y[j+1]<y[j+2])
			{
				oo[j+1]=y[j];
				y[j+1]=y[j+2];
				y[j+1]=oo[j+1];
			}
    	}
	}
	int z=1;
	while(1!=m)
	{
		for(int i=1;i<=n*m;i++)
		{			
			while(k<=n+1)
			{
				a[k][z]=y[i];
				if(r==a[k][z])
				{
					cout<<k<<" "<<z;
					return 0;
				}
			}
		}
	}
	return 0;
}
