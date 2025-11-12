#include<bits/stdc++.h>
using namespace std;
int m,n,i,j,c[12],z[12][12],a,l,p,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n*m;i++)
	{
		cin>>c[i];
		if(i==0)
		{
			a=c[i];
			l=i;
		}
	}	
	for(i=0;i<n*m;i++)
		for(j=0;j<n*m;j++)
		{
			if(c[i]>c[j])
			{
				swap(c[i],c[j]);
				if(c[i]==a)
					l=j;
				if(c[j]==a)
					l=i;			
			}
		}
	for(int k=0;k<n;k++)
		for(j=0;j<n;j++)
		{
			if(j%2==0 || j==0)
			{
				for(i=0;i<m;i++)
				{
					z[j][i]=c[p];
					if(z[j][i]==a)
					{
						x=i;
						y=j;
					}
					p++;
				}
			}
			else
			{
				for(i=m-1;i>=0;i--)
				{
					z[j][i]=c[p];
					if(z[j][i]==a)
					{
						x=i;
						y=j;
					}
					p++;
				}
			}
		}
	cout<<y+1<<" "<<x+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
