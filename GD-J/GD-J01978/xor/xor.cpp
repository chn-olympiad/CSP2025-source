#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],sxor[500001];
struct node{
	int l,r;
}s[500001];
bool cmp(node x,node y)
{
	return x.r<y.r;
}
int ans=0,cnt=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		sxor[i]=sxor[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((sxor[j]^sxor[i-1])==k){
				cnt++;
				s[cnt].l=i;s[cnt].r=j;
			}
		}
	}
	sort(s+1,s+cnt+1,cmp);
	int pos=0;
	for(int i=1;i<=cnt;i++)
	{
		if(s[i].l>pos){
			ans++;
			pos=s[i].r;
		}
	}
	printf("%d",ans);
	return 0;
}
