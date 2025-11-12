#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",std.in);
	freopen("seat.out","w",std.out);
	int n,m,c,r,x;
	int a[121],b[121],c=[11][11];
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	    cin>>a[i];
	    b[i]=a[i];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(a[i]<a[j])
			{
				b[i]=a[j];
				b[j]=a[i];
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(b[i]=a[1])
		{
			x=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j%2==1)
			{
				c[i][j]=b[(j-1)*n+i];
				if(x==(j-1)*n+i)
				{
					cout<<i<<j;
					return 0;
				}
			}
			if(j%2==0)
			{
				c[i][j]=b[j*n-i+1];	
				if(x==j*n-i+1)
				{
					cout<<i<<j;
					return 0;
				}
			}
		}
	}
	return 0;
	fclose("seat.in",std.in);
	fclose("seat.out",std.out);
}