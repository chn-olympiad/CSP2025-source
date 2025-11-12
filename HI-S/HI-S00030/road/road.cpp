#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+5,P=5e4,K=20;
long long fa[N],n,m,k,c[K],a[K][N];
struct node
{
	long long u,v,w;
	bool pos=false;
}mp[M+P];
long long find(long long x)
{
	if(x==fa[x]) return x;
	return (fa[x]=find(fa[x]));
}
bool cmp(node nxy,node lyk){return nxy.w<lyk.w;}
long long kruskal(long long len)
{
	sort(mp+1,mp+len+1,cmp);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	long long ans=0;
	for(int i=1;i<len;i++)
	{
		long long x=mp[i].u,y=mp[i].v,z=mp[i].w;
		x=find(x),y=find(y);
		if(x==y) continue;
		fa[x]=y;
		ans+=z;
	}
	return ans;
}
void simple_work()
{
	long long ans=kruskal(m);
	printf("%lld\n",ans);
	return;
}
void middle_work()
{
	long long top=m;
	for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) mp[++top].w=a[i][j],mp[top].u=n+i,mp[top].v=j,mp[top].pos=1;
	long long ans=kruskal(top);
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	
	scanf("%lld%lld%lld",&n,&m,&k);
	bool flag=false;
	for(int i=1;i<=m;i++)
	{
		long long uu,vv,ww;
		scanf("%lld%lld%lld",&uu,&vv,&ww);
		mp[i].u=uu,mp[i].v=vv,mp[i].w=ww;
	}
	
	if(!k){simple_work();return 0;}//15:27写完16pts做法，没有样例对证 
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		if(c[i]) flag=true;
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	if(!flag) {middle_work();return 0;}//15:55写完48pts做法，但是没有调试成功 
	//16.19发现错误，大样例过了 
	else simple_work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
*/
