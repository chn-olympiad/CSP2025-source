#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int b[101];
int a[11][11];
int x=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>b[i];
	}
	x=b[0];
	sort(b,b+n*m);
	int y=n*m-1;
     for(int i=1;i<=n;i++)
     {
     	for(int j=1;j<=m;j++)
     	{
     	    if(a[i][j]==x);
     	    {
     	    	cout<<i<<" "<<j+1<<endl;
     	    	return 0;
			 }
			 a[i][j]=b[y];
			 y--;	
		}
	 }
    return 0;   
}
