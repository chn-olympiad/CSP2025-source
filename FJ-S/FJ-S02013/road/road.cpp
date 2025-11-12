#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,fa[200010],ans=1e18,c[21],a[21][200010];
struct edge{
	int x,y,z,id;
	bool pd;
}e[2000010],e1[2000010];
bool cmp(edge a,edge b){
	return a.z<b.z;
}
bool cnp(edge a,edge b){
	return a.id<b.id;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void f(int n,int m,bool pd){
	for(int i=1;i<=n+10;i++)fa[i]=i;
	if(!pd){
		for(int i=1;i<=m;i++)e[i].id=i;
		sort(e+1,e+m+1,cmp);
	}
	else{
		for(int i=1;i<=m;i++)e1[i].id=i;
		sort(e1+1,e1+m+1,cmp);
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		int x,y,z;
		if(!pd)x=e[i].x,y=e[i].y,z=e[i].z;
		else x=e1[i].x,y=e1[i].y,z=e1[i].z;
		int fx=find(x),fy=find(y);
		if(fx==fy)continue;
		fa[fy]=fx;
		if(!pd)e[i].pd=1;
		else e1[i].pd=1;
		if(++cnt==n-1){
			if(!pd)sort(e+1,e+m+1,cnp);
			else sort(e1+1,e1+m+1,cnp);
			return;
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].x>>e[i].y>>e[i].z;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	f(n,m,0);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(e[i].pd){
			cnt++;
			e1[cnt]=e[i];e1[cnt].pd=0;
		}
	}
	m=cnt;
	for(int xx=0;xx<(1<<k);xx++){
		int sum=0,tmp=m,cnt=0;
		for(int i=1;i<=k;i++){
			if((xx>>(i-1))&1){
				sum+=c[i];cnt++;
				for(int j=1;j<=n;j++)e1[++m]={j,n+i,a[i][j]};
			}
		}
		f(n+cnt,m,1);
		for(int i=1;i<=m;i++){
			if(e1[i].pd)sum+=e1[i].z,e1[i].pd=0;
		}
		ans=min(ans,sum);
		m=tmp;
	}
	cout<<ans;
}
/*
166616661666166616661666
*/
