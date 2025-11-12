#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int b[400];
int n,m;
int g;
bool cmp(int a,int b)
{
	return a>b;
}
int cnt=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
    	cin>>b[i];
	}
	g=b[1];
	sort(b+1,b+n*m+1,cmp);
    for(int j=1;j<=m;j++)
    {
    	if(j%2==1)
    	{
    	for(int i=1;i<=n;i++)
    	{
    		a[i][j]=b[cnt++];
    	//	cout<<a[i][j]<<" ";
    		if(a[i][j]==g) 
    		{
    			cout<<j<<" "<<i;
    			return 0;
			}
		}
	}
	else{
		for(int i=n;i>=1;i--)
		{
			a[i][j]=b[cnt++];
		//	cout<<a[i][j]<<" ";
			if(a[i][j]==g) 
    		{
    			cout<<j<<" "<<i;
    			return 0;
			}
		}
	}
	}
	
	return 0;
 } 
