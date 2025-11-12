#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
vector<int>a,b,c;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		int num=0,cnt=0,tot=0,ans=0;
		for (int i=1; i<=n; i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if (x>=y&&x>=z)
			{
				num++;
				ans+=x;
				if (y>=z) a.push_back(x-y);
				else a.push_back(x-z);
			}
			else if (y>=x&&y>=z)
			{
				cnt++;
				ans+=y;
				if (x>=z) b.push_back(y-x);
				else b.push_back(y-z);
			}
			else if (z>=x&&z>=y)
			{
				tot++;
				ans+=z;
				if (x>=y) c.push_back(z-x);
				else c.push_back(z-y);
			}
		}
		int mid=max(num,max(cnt,tot));
		if (mid==num)
		{
			if (mid>n/2)
			{
				sort(a.begin(),a.end());
				for (int i=0; i<(mid-n/2); i++) ans-=a[i];
			}
		}
		else if (mid==cnt)
		{
			if (mid>n/2)
			{
				sort(b.begin(),b.end());
				for (int i=0; i<(mid-n/2); i++) ans-=b[i];
			}
		}
		else if (mid==tot)
		{
			if (mid>n/2)
			{
				sort(c.begin(),c.end());
				for (int i=0; i<(mid-n/2); i++) ans-=c[i];
			}
		}
		printf("%d\n",ans);
		a.clear();
		b.clear();
		c.clear();
	}
	return 0;
}
