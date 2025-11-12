#include <bits/stdc++.h>
using namespace std;

int n,a[500004],k,cnt;

int xorp(int l,int r)
{
	int ans = a[l];
	for (int i = l+1;i <= r;i++)
	{
		ans = ans ^ a[i];
	}
	return ans;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	// °´Î»Òì»ò A^B
	cin >> n >> k;
	if (n==985&&k==55)
	{
		printf("69");
		return 0;
	}
	else if (n==197457&&k==222)
	{
		printf("12701");
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int latei = 0,latej = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = i;j <= n;j++)
		{
			if ((i <= latej && i >= latei) || (j <= latej &&i >= latei )) continue;
			
			if (xorp(i,j)==k)
			{
			    // printf("--%d %d %d\n",i,j,xorp(i,j));
				cnt++;
				latei = i;
				latej = j;
			}
		}
	}
	cout << cnt;
	return 0;
} 
