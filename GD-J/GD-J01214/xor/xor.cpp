#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int s,cnt,ans;
int h[500005];
struct node
{
	int l,r;
}e[500050];
vector<int> v[2000050];
bool cmp(node q,node p)
{
	if(q.r==p.r) return q.l<p.l;
	return q.r<p.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) h[i]=h[i-1]^a[i];
	for(int i=1;i<=n;i++)
	{
		v[h[i]].push_back(i);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<v[h[i]^k].size();j++)
		{
			if(v[h[i]^k][j]<=i) continue;
			e[++cnt].l=i+1;
			e[cnt].r=v[h[i]^k][j];
			break;	
		}
	}
	sort(e+1,e+1+cnt,cmp);
	int R=e[1].r;
	ans++;
	for(int i=2;i<=cnt;i++)
	{
		if(e[i].l>R)
		{
			R=e[i].r;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
