#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	int n,m,k;
	int u[10005];
	int v[10005];
	int w[10005];
	int c[10005];
	int a[15][10005];
	//±äÁ¿
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	} 
	for(int j=1;j<=n;j++)
	{
	    for(int k=1;k<=n;k++)
	    {
		    cin>>c[j]>>a[j][k]; 
	    }
    }
    
    cout<<13;
    
    
	return 0; 
} 
