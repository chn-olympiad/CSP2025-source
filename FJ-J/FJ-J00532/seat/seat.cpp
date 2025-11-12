#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b)
{
	return a>b;
}
long long a[105],b[15][15];
int main()//#########################
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//###############################
	long long n,m,r;
	cin>>n>>m>>r;
	a[1]=r;
	for(long long j=2;j<=n*m;j++) cin>>a[j];
	sort(a+1,a+n*m+1,cmp);
	long long i=0;
	for(long long j=1;j<=m;j++)
		if(j%2)
			for(int k=1;k<=n;k++)
			{
				i++;
				b[k][j]=a[i];
			}	
		else
			for(int k=n;k>=1;k--)
			{
				i++;
				b[k][j]=a[i];
			}	
//	for(int i=1;i<=n*m;i++) cout<<a[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<b[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(b[i][j]==r)
				cout<<j<<" "<<i;
	return 0;
}
