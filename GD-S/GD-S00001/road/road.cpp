#include<bits/stdc++.h>
using namespace std;
struct qq{
	long long w,u,v;
}wa[2000005];
long long fa[10005];
long long ma[15][10005];
long long n,m,k,ans=0;
int find(int x){
	if(x==fa[x])return x;
	else return fa[x]=find(fa[x]);
}
bool cmp(qq aa,qq bb){
	return aa.w<bb.w;
}
void so1(){
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(wa+1,wa+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=find(wa[i].u),y=find(wa[i].v);
		if(x!=y){
			fa[x]=y;
			ans+=wa[i].w;
		}
	}
	cout<<ans;
}
void so2(){
	for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)wa[++m].u=n+i,wa[m].v=j,wa[m].w=ma[i][j];
	n+=k;
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(wa+1,wa+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=find(wa[i].u),y=find(wa[i].v);
		if(x!=y){
			fa[x]=y;
			ans+=wa[i].w;
		}
	}
	cout<<ans;
}
void work(int x){
	long long anss=0;
	long i=0;
	int t=0;
	while(x){
		++t;
		if(x%2){
			i++;
			for(int j=1;j<=n;j++)wa[++m].u=n+i,wa[m].v=j,wa[m].w=ma[t][j];
			anss+=ma[t][0];
		}
		x/=2;
	}
	int y=n+i;
	for(int i=1;i<=y;i++)fa[i]=i;
	sort(wa+1,wa+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=find(wa[i].u),y=find(wa[i].v);
		if(x!=y){
			fa[x]=y;
			anss+=wa[i].w;
		}
	}
	ans=min(ans,anss);
}
void so3(){
	ans=1e9;
	for(int i=0;i<=(1<<k)-1;i++)work(i);
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int fl1=1;
	for(int i=1;i<=m;i++)cin>>wa[i].u>>wa[i].v>>wa[i].w;
	for(int i=1;i<=k;i++)for(int j=0;j<=n;j++)cin>>ma[i][j];
	for(int i=1;i<=k;i++)if(ma[i][0]!=0)fl1=0;
	if(k==0)so1();
	else if(fl1)so2();
	else so3();
	return 0;
}
