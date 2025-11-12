#include<bits/stdc++.h>
using namespace std;
long long a[10005][10005],b[10000005],n,m,num,p;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++)
	{
		cin>>b[i];
	}
	p=b[1];
	sort(b+1,b+num+1,cmp);
	
	for(int i=1;i<=n;i++)
	{
		int u=0;
		for(int j=1;j<=m;j++)
	    {
        	a[i][j]=b[i+u];
        	u+=n;
    	}
    }
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==p)
			{
				cout<<j<<' '<<i;
			}
		}
	}
	return 0;
} 
