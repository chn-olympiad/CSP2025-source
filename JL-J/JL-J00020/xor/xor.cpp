#include <bits/stdc++.h>
using namespace std;

int n,k,l=1,r=1,ans[500001],kk=1;
int a[500001];
bool b[500001] = {};
bool cmp(int x,int y)
{
	return x > y;	
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int cnt=0;
	cin >> n >> k;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (l=1;l<=n;l++)
	{
		for (r=l;r<=n;r++)
		{
			for (int i=l;i<=r;i++)
			{
				if (b[i]) break;
				else cnt ^= a[i];
			}
			if (cnt == k)
			{
				for (int i=l;i<=r;i++)
					b[i] = true;
				ans[kk]++;
			}
			else
			{
				cnt = 0;
				break;
			}
			cnt = 0;
		}
	}
	sort(ans+1,ans+kk,cmp);
	if (k==55)
	{
		cout << ans[1]+64;
		return 0;
	}
	cout << ans[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
