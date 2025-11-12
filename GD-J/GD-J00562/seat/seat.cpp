#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[1000000];
long long x,y;
long long youself;
long long zw[1000][1000];

int cmp(long long a,long long b)
{
	if(a<b)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	
	youself=a[1];
	int k=1;
	sort(a+1,a+n*m+1,cmp);
	/*for(int i=1;i<=n*m;i++)
	{
		cout<<a[i]<<" ";
	}*/
	
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			int i=1;
			while(i<=n)
			{
				zw[i][j]=a[k];
				//cout<<"i:"<<i<<" j:"<<j<<" ="<<a[k]<<endl;
				k++;
				i++;
			}
		}
		else
		{
			int i=n;
			while(i>=1)
			{
				zw[i][j]=a[k];
				//cout<<"i:"<<i<<" j:"<<j<<" ="<<a[k]<<endl;
				k++;
				i--;
			}
		}
		
	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(zw[i][j]==youself)
			{
				x=i;
				y=j;
				break;
			}
			
			//cout<<zw[i][j]<<" ";
		}
		//cout<<endl;
	}
	cout<<y<<" "<<x;
	return 0;
}

/*
3 3 
94 95 96 97 98 99 100 93 92
*/
