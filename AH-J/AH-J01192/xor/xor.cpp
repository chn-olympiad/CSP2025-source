#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long a[N],n,k,ans;
bool st[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	memset(st,false,sizeof st);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]==k)
		{
			ans++;
			st[i]=true;
		}
	}
	if(k==0) 
	{
		printf("%lld",ans);
		return 0;
	}
	int x=0;
	for(int i=1;i<=n;i++)
	{
		if(st[i]==true) x=0;
		else
		{
			x^=a[i];
			if(x==k)
			{
				ans++;
				x=0;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
