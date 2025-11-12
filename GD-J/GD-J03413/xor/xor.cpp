#include <bits/stdc++.h>
using namespace std;
int n,a[500005][20],k,sum[500005][20],x,k1[20],f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>x;
		for (int j=19;j>=0;j--){sum[i][j]=sum[i-1][j];if (x>=(1<<j)){a[i][j]=1;x-=(1<<j);sum[i][j]=!(sum[i-1][j]);}}
		
	}
	for (int i=19;i>=0;i--){
		if (k>=(1<<i)){k1[i]=1;k-=(1<<i);}
	}
	for (int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		for (int j=i;j;j--)
		{
			int flag=0;
			for (int l=0;l<=19;l++){
				if (k1[l]!=abs(sum[i][l]-sum[j-1][l])){
					flag=1;
					break;
				}
			}
			if (flag==0){
				f[i]=f[j-1]+1;
				break;
			}
		}
	}
	cout<<f[n];
	return 0;
}
