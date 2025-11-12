#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k;
long long ans;
int a[maxn],s[maxn];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	s[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int xx=s[i]^s[j];
			if(xx==k)
			{
				ans++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
