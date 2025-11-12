#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,k;
int a[MAXN],t[MAXN];
int ans;
int l,r,p;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),t[i]=a[i]^t[i-1];
	l=r=p=1;
	while(l<=n&&r<=n)
	{
		for(l=p;l<=r;l++)
		{
			if((t[r]^t[l-1])==k)
			{
				p=r+1;
				ans++;
				break;
			}
		}
		r++;
	}
	printf("%d",ans);
	return 0;
}
