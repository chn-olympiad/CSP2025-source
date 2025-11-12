#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll x=0,f=1;
	char c = getchar();
	while(c>'9'||c<'0'){if(c == '-')f = -1;c = getchar();}
	while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
	return x*f;
}
int n,m,k,fa[20010],ans,vl[12];
bool f[4000010];
struct node
{
	int u,v,w;
}e[4000020];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i = 1;i <= m;i ++){
		int x=read(),y=read(),val=read();
		e[i] = {x,y,val};
		e[i+m+n*k] = {y,x,val};
	}
	for(int i = 1;i <= k;i ++){
		int val=read();
		vl[n+i]=val;f[n+i]=true;
		for(int j = 1;j <= n;j ++){
			int ww=read();
			int zb = m+(i-1)*n+j;
			e[zb] = {n+i,j,ww+val};
			e[zb+m] = {j,n+i,ww+val};
		}
	}
	sort(e+1,e+1+m+n*k,
	[](node x,node y){
		return x.w<y.w;
	});
	for(int i = 1;i <= n+10;i ++)fa[i] = i;
	int cnt = 0;
	int p=n,sum=0,kk=2*(m+n*k);
	for(int i = 1;i <= kk;i ++){
		if(cnt==p-1)break;
		int x = e[i].u,y=e[i].v,val=e[i].w;
		int fx=find(x),fy=find(y);
		if(fx==fy)continue;
		int ss=max(x,y);
		if(ss>=n+1&&ss<=n+k){
			if(f[ss]) f[ss]=false,p++;
			else if(!f[ss]) sum+=vl[ss];
		}
		fx = find(fy);
		ans+=val;
		cnt++;
	}
	cout<<ans-sum;
	return 0;
}
