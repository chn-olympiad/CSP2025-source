#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=(1<<20)+10;
int n,k,a[N],pre[N],cnt[M],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pre[i]=pre[i-1]^a[i];
	}
	cnt[0]++;
	for(int i=1,lst=0;i<=n;i++)
	{
		if(cnt[k^pre[i]]>0)
		{
			ans++;
			for(int j=lst;j<i;j++)
			  cnt[pre[j]]--;
			lst=i;
		}
		cnt[pre[i]]++;
	}
	printf("%d",ans);
	return 0;
}
