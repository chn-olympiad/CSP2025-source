#include <iostream>
using namespace std;
int n,k;
int z,ans;
long long a[500005];
long long sum[500005];
long long y;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		sum[i]=a[i]^sum[i-1];
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=i-1;j>=0;j--)
		{
			y=sum[i]^sum[j];
			if(y==k)
			{
				ans++;
				i=j;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
