#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		cnt=a[i];
		if(cnt==k)
		{
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++)
		{
			cnt=cnt^a[j];
			if(cnt==k) 
			{
				i=j;ans++;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
/*
x   x    ooo    rrrrr
 x x    o   o   r    r
  x     o   o   rrrrr
 x x    o   o   r r
x   x    ooo    r   r
UID:1151818
*/
