#include<bits/stdc++.h>
using namespace std;
int i,n;
int a[100101][5],r[101010][5];
int sum[10010];
long long f[10010][5];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<=n;i++)
		for(int j=1;j<=n-1;j++)
			cout<<a[i][j];
		for(int i=0;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				r[i][j]=0;
			r[i][j]=a[i][j];
			}
		}
		for(int i=0;i<=n;i++)
		{
			if(num[i]=n/2)
			{
				r[i][j]=max(max(a[i-1][1],f[i-1][2]),r[i-1][3]);
				sum[1]++;
			}
			if(num[i]+=/2)
			{
				r[i][j]=max(max(a[i-1][1],f[i-1][2]),r[i-1][3]);
				sum[2]++;
			}
		}
		return 0;
}
