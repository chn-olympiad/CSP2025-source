#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
long long ans,cu=998244353,l;
void cl(int i,int j,int s)
{
	j--;
	s-=a[i];
	if(j==0)
	{
		if(s<0)ans++;
		return ;
	}
	for(int q=i-1;q>=j;q--)
	{
		if(j==1&&s>=a[q])break;
		cl(q,j,s);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=3;i<=n;i++)
		for(int q=i;q>=3;q--)
		{	
			l=ans;
			cl(i,q,a[i]*2);
			if(ans==l)break;
			ans%=cu;
		}
		printf("%lld",ans);
	return 0;
}
