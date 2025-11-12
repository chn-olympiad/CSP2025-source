#include<iostream>
using namespace std;

int n,k;
int a[500005];
int b[3][500005];
int count=0;
int r=50050050;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=n;i>=1;i--)
	{
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i-1;j++)
		{
			if(j==0)
			{
				b[1][j]=a[i];
			}
			else
			{
				b[1][j]=a[i]^b[0][j-1];
			}
		}
		for(int j=0;j<=i-1;j++)
		{
			b[0][j]=b[1][j];
		}
		for(int j=0;j<=i-1;j++)
		{
			if(b[0][j]==k&&(n-i+1+j)<r)
			{
				count++;
				r=n-i+1;
			}
		}
	}
//	for(int i=0;i<=n;i++)
//	{
//		for(int j=0;j<=n-1;j++)
//		{
//			cout<<b[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	cout<<count;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
