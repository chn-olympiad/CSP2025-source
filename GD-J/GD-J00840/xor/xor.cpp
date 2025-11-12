#include <bits/stdc++.h>
using namespace std;
int a[100005];
struct node
{
	int x,y;
}b[100005];
bool cmp(node x,node y)
{
	if(x.x == y.x)
	{
		return x.y<y.y;
	}
	return x.x<y.x;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	int x = 0,cnt = 0;
	for(int i = 1;i<=n;i++)
	{
		for(int j = i;j<=n;j++)
		{
			x^=a[j];
			if(x == k)
			{
				b[++cnt].x = i;
				b[cnt].y = j;
			}
		}
		x = 0;
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i = 1;i<=cnt;i++)
	{
		for(int j = i+1;j<=cnt;j++)
		{
			if(b[j].x>b[i].x&&b[j].y<b[i].y)
			{
				b[i].x = b[i].x = -1000000000;
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	x = 0;
	int ans = 0;
	for(int i = 1;i<=cnt;i++)
	{
		if(x<b[i].x)
		{
			ans++;
			x = b[i].y;
		}
	}
	cout<<ans;
	return 0;
}
