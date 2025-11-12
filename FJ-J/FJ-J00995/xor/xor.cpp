#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	int l,r;
}ps[500005];
int n,cnt;
ll a[500005],op;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&op);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for (int i=n;i>=1;i--)
	{
		ll sum=0;
		for (int j=i;j>=1;j--)
		{
			sum^=a[j];
			if (sum==op)
			{
				ps[++cnt]={j,i};
				break;
			}
		}
	}
	int ans=0,last=0;
	for (int i=cnt;i>=1;i--)
	{
		if (ps[i].l>last)
		{
			ans++;
			last=ps[i].r;
		}
	}
	printf("%d",ans);
	return 0;
	}

