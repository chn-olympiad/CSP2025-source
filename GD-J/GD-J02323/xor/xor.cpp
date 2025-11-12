#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],s[N];
struct node{
	int l,r;
}g[1000005];
int cnt;
bool cmp(node x,node y)
{
	if(x.r==y.r)return x.l<y.l;
	return x.r<y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if((s[i]^s[j])==k)
			{
			//	cout<<j+1<<" "<<i<<endl;
				g[++cnt]={j+1,i};
			}
		}
	}
	sort(g+1,g+1+cnt,cmp);
	int r=0,sum=0;
	for(int i=1;i<=cnt;i++)
	{
		if(g[i].l>r)
		{
			r=g[i].r;
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
}
