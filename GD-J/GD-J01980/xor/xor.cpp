#include <iostream>
using namespace std;
int a[500005];
int exor[2][500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int lyr = 1;
	int r = 1;
	for(int i = n; i >= 1; i--)
	{
		exor[1][i] = a[i];
		if (exor[1][i] == k)
		{
			ans++;
			exor[1][i] = -1;
		}
	}
	while(lyr <= n)
	{
		int cnt = 0;
		int dr = r;
		r = r ^ 1;
		for(int i = n - lyr; i >= 1; i--)
		{
			if(exor[dr][i+1] != -1 && exor[dr][i] != -1)
			{
				exor[r][i] = exor[dr][i] ^ exor[dr][i+1];
				cnt++;
			} else {
				exor[r][i] = -1;
			}
			if(exor[r][i] == k)
			{
				ans++;
				for(int j=i;j>=i-lyr+1;j--)
				{
					if(j == 0)
					{
						break;
					}
					exor[r][j] = -1;
				}
			}
		}
		if(cnt==0) break;
		lyr++;
	}
	cout << ans << endl;
	return 0;
}
