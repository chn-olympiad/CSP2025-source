#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1010];
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int p=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	
	int s=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p)
			s=i;
	}
	int b[110][110];
	int x=1,j=1;
	for(int i=1;i<=m;i+=2)
	{
		for(int j=1;j<=n;j++)
		{
			b[j][i]=x;
			x++;
		}
		x=x+n;
	}
	x=n+1;
	
	
	for(int i=2;i<=m;i+=2)
	{
		for(int j=n;j>=1;j--)
		{
			b[j][i]=x;
			x++;
		}
		x=x+n;
	} 
	
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[i][j]==s)
				cout<<j<<" "<<i; 
		}
	}
	
    return 0;
}

/*
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);

*/ 


