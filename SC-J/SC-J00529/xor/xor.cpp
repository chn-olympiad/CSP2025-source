#include<bits/stdc++.h>
using namespace std;
#define maxn 500001
int n,k,cnt;
int l,r;
int a[maxn],sum[maxn];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
		for(int j=i;j>=1;j--)
		{
			if((sum[i]^sum[j-1])==k)
			{
				if(!cnt)l=j,r=i,cnt++;
				else if(((l>=j&&l<=i)||(r>=j&&l<=i)||(l>=j&&r<=i)))
					continue;
				else l=min(l,j),r=max(r,i),cnt++;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
/*
4 0
2 1 0 3
*/