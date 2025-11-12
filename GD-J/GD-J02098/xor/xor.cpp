#include<bits/stdc++.h>
using namespace std;
const int N=4e4+10,M=1e6+10; 
struct nd{int l,r;}yh[M];
int a[M];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;scanf("%d%d",&n,&k);int sum=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int x=0;
		for(int j=i;j<=n;j++)
		{
			x^=a[j];
			if(x==k)yh[++sum]={i,j};
		}
	}
	int last=0;int ans=0;
	for(int i=1;i<=sum;i++)
		if(yh[i].l>last)
		{
			ans++;
			last=yh[i].r;
		}
	printf("%d\n",ans);
	return 0;
}
