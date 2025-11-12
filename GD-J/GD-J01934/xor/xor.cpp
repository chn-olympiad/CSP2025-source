#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],tmp,vis[2097200],pos,ans,maxx;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=2097157;i++) vis[i]=-0x7fffffff;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) s[i]=(s[i-1]^a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			ans++;
			pos=i;
			vis[s[i]]=i;
			continue;
		}
		tmp=k^s[i];
		if(vis[tmp]>=pos)
		{
			pos=i;
			ans++;
		}
		vis[s[i]]=i;
	}
	printf("%d",ans);
	return 0;
}

