#include<bits/stdc++.h>
using namespace std;
struct k
{
	int from,to,v;
};
k edge[1100000];
bool cmp(k a,k b)
{
	return a.v<b.v;
}
int rl[110000];
void init(int n)
{
	for(int i=1;i<=n;i++) rl[i]=i;
}
int find(int k)
{
	if(rl[k]==k) return k;
	return rl[k]=find(rl[k]);
}
bool merge(int a,int b)
{
	int l=find(a),r=find(b);
	if(l!=r)
	{
		rl[l]=r;
		return true;
	}
	return false;
}
long long kru(int n,int m)
{
	init(n);
	int cnt=0;
	long long ans=0;
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(cnt==n-1) return ans;
		if(merge(edge[i].from,edge[i].to))
		{
			ans+=edge[i].v;
			cnt++;
		}
	}
	return 0;
}
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d %d %d",&edge[i].from,&edge[i].to,&edge[i].v);
	long long ans=kru(n,m);
	printf("%lld",ans);
	
	
	
	
	
	return 0;
}
