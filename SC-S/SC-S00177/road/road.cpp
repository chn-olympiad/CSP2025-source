#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long num=0;
	while(1)
	{
		char a=getchar();
		if(a==' '||a=='\n')return num;
		num=num*10+(long long)(a-'0');
	}
}
struct node{
	long long x,y,w;
}edge[1000005];
struct node2{
	long long x,y,w;
}kf[1000002];
bool cmp(const node a,const node b){return a.w<b.w;}
bool cmp2(const node2 a,const node2 b){return a.w<b.w;}
long long n,m,k,lk[105],bk[6][50002],f[500005],cs[15],bgans=9999999999999999;
long long find(long long mb)
{
	if(f[mb]==mb)return mb;
	f[mb]=find(f[mb]);
	return f[mb];
}
long long check()
{
	long long ans=0;
	for(int i=1;i<=k;i++)ans+=cs[i]*lk[i];
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=n*k;i++)kf[i].w=200000000000000,kf[i].y=-1;
	long long flg=0;
	for(int i=1;i<=k;i++)
	if(cs[i])
	{
		for(int j=1;j<=n;j++){
			kf[flg*n+j].w=bk[i][j];
			kf[flg*n+j].x=i;
			kf[flg*n+j].y=j;
		}
		flg++;
	}
	sort(kf+1,kf+flg*n+1,cmp2);
	long long zzx=0,zzy=0;
	for(int i=1;i<=m+n*flg;i++)
	{
		if((edge[zzx+1].w<kf[zzy+1].w&&zzx<=m-1)||zzy>=flg*n){
			zzx++;
			if(find(edge[zzx].x)!=find(edge[zzx].y))f[find(edge[zzx].y)]=find(edge[zzx].x),ans+=edge[zzx].w;
		}
		else{
			zzy++;
			if(find(kf[zzy].x+n)!=find(kf[zzy].y))f[find(kf[zzy].y)]=find(kf[zzy].x+n),ans+=kf[zzy].w;
		}
	}
	return ans;
}
void dfs(int num){
	if(num==k+1)
	{
		long long fh=check();
		bgans=min(bgans,fh);
		return;
	}
	cs[num]=1;
	dfs(num+1);
	cs[num]=0;
	dfs(num+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
		edge[i].x=read(),edge[i].y=read(),edge[i].w=read();
	for(int i=1;i<=k;i++)
	{
		lk[i]=read();
		for(int j=1;j<=n;j++)bk[i][j]=read();
	}
	sort(edge+1,edge+m+1,cmp);
	dfs(1);
	cout<<bgans<<endl;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/