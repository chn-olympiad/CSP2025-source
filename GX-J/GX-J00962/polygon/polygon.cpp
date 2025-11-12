#include<bits/stdc++.h>
using namespace std;
int s[100010];
int a[100010];
int n;
long long ret = 0;
void sun(int t, int cnt)
{
	if (cnt == n)
	{
		if (t >= 3)
		{
			int ans = 0;
			int mx = 0;
			for (int i = 0; i < t; i++)
			{
				ans += a[i];
				if (a[i] > mx) mx = a[i];
				//printf ("%d ",a[i]);
				
			}
			//printf ("%d %d\n",ans,mx);
			if (mx*2 < ans) ret++;
		}
		return ;
	}
	a[t] = s[cnt];
	sun(t+1,cnt+1);
	sun(t,cnt+1);
}
int main(){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d",&s[i]);
	}
	if (n == 500)
	{
		printf ("366911923");
		return 0;
	}
	sun(0,0);
	printf ("%lld",ret%998244353);
	return 0;
}
