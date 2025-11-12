#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[3],b,e,d;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i%2]);
		if(a[i%2]==1)b++;
		if(a[i%2]==0)
		{
			e++;
			ans+=d/2;
			d=0;
		}
		if(a[i%2]==1)d++;
	}
	if(d!=0)ans+=d/2;
	if(k>1&&k<0)printf("0");
	else if(k==1)printf("%d",b);
	else printf("%d",ans+e);
	return 0;
}
