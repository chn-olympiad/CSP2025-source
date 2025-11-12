#include<bits/stdc++.h>
using namespace std;
int a,f[500001],q[21000000],k,n,cnt,sum,las;
struct node
{
	int x, y;
}u[500001];
bool cmp(node a,node b)
{
	return a.y < b.y;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a;
		f[i] = f[i-1] ^ a;
	}
	for(int i = 1;i <= n;i++)
	{
		int s = f[i] ^ k;
		if(s == 0)
		{
			if(q[0] == 0)
			{
				u[++cnt].x = 1;
				u[cnt].y = i;
			}
			else
			{
				u[++cnt].x = q[0]+1;
				u[cnt].y = i;
			}
		}
		else
		{
			if(q[s])
			{
				u[++cnt].x = q[s]+1;
				u[cnt].y = i;
			}
		}
		q[f[i]] = i;
	}
	sort(u+1,u+cnt+1,cmp);
	for(int i = 1;i <= cnt;i++)
	{
		if(u[i].x > las)
		{
			sum++;
			las = u[i].y;
		}
	}
	cout << sum;
	return 0;
} 