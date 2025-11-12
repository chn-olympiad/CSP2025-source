#include <bits/stdc++.h>
using namespace std;

int n,a[5001],l,r,ans,cnt,maxn=-114514;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (l=1;l<=n;l++)
	{
		for (r=l+1;r<=n;r++)
		{
			for (int i=l;i<=r;i++)
			{
				cnt += a[i];
				if (a[i] > maxn)
				{
					maxn = a[i];
				}
			}
			bool flag = ((maxn*2) < cnt) ? true:false;
			if (flag) ans++;
			else break;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
