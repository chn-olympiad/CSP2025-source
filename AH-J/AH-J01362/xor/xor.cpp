#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n,k,a[N],ans=-2100000000;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int cnt=0,s=a[i];
		for(int j=i+1;j<=n;j++)
		{
			if(s==k)
			{
				cnt++;
				s=a[j];
				continue;
			}
			s=s^a[j];
		}
		if(s==k) cnt++;
		ans=max(ans,cnt);
	}
	printf("%d",ans);
	return 0;
}
