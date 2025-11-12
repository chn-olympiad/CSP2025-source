#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in.txt","r",stdin);
	freopen("seat.out.txt","w",stdout);
	int n,m,s,time=0;
	cin>>m>>n;
	int seat[n][m],x[m*n];
	for(int i=0;i<n*m;i++) cin>>x[i];
	s=x[0];
	for(int i=1;i<=m*n-1;i++) for(int j=0;j<m*n-i;j++)if(x[j]<x[j+1]) swap(x[j],x[j+i]);
	for(int i=0;i<n*m;i++) cout<<x[i]<<" ";
	for(int i=0;i<n;i++)
	{
		if((i+1)%2!=0) 
		{
			for(int j=0;j<m;j++) 
			{
				seat[i+1][j+1]=x[time];
				if(x[time]==s)
				{
					cout<<i+1<<" "<<j+1<<endl;
					return 0;
				}
				time++;
			}
		}
		else
		{
			for(int q=m-1;q>=0;q--) 
			{
				seat[i+1][q+1]=x[time];
				if(x[time]==s)
				{
					cout<<i+1<<" "<<q+1<<endl;
					return 0;
				}
				time++;
			}
		}
	}
}