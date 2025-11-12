#include<bits/stdc++.h>
using namespace std;

const int N = 1e7;
const int MOD = 998244353;
int a[N],b[N];
int n,ret = 0;

int get(int cnt,int now,int i)
{
	if(cnt>=n)
	{
		if(now==i)
		{
			int mx = -1,num = 0;
			for(int i = 1;i <= i;i++)
			{
				mx = max(mx,b[i]);
				num += b[i];
			}
			if(num>mx*2) ret = (ret+1)%MOD;
		}
	}
	b[cnt] = a[now];
	get(cnt++,now++,i);
	get(cnt,now++,i);
}

int main () 
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
	}
	long long ret = 0;
	for(int i = 3;i <= n;i++)
	{
		int r = -1;
		while(r==ret)
		{
			r = ret;
			get(1,0,i);
		}
	}
	printf("%lld",ret);
	return 0;
}
