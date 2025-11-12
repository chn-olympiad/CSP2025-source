#include<bits/stdc++.h>
using namespace std;

int l = 1, r = 1, tmp;
int a[500100],ans;
int n, k;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	tmp = a[1];
	while(r<=n)
	{
		if(tmp == k)
		{
			l = r + 1, r = l, ans++, tmp = a[l];
			printf("%d | [%d %d]\n", tmp, l, r);
		}
		else if(tmp < k)
		{
			tmp = tmp ^ a[++r];
			printf("%d | [%d %d]\n", tmp, l, r);
		}
		else if(tmp > k)
		{
			tmp = tmp ^ a[l++];
			printf("%d | [%d %d]\n", tmp, l, r);
		}
	}
	cout<<ans;
	return 0;
}
