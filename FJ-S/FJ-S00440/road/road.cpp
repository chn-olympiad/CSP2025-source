#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int _N=1e4+10;
int a[11][_N],a_mi[11][3]; 
bool flag[11];
int n,m,k;
struct E{
	int u,v,w;
}e[N];
int tot;
void add(int u,int v,int w){
	e[++tot].u=u;
	e[tot].v=v;
	e[tot].w=w;
}
bool cmp(E i, E j){
	return i.w<j.w;
}
long long ans;
bool vis[_N];
int cnt;
void krske(){
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,unknow,unknown=-1;
		if(!vis[u]){
			unknow=u;
			if(!vis[v]) unknown=v;
		}
		else if(!vis[v]) unknow=v;
		else continue;
		long long mi=INT_MAX;
		int miid;
		for(int i=1;i<=k;i++){
			long long mivo;
			if(unknown==-1){
				if(a[i][unknow]!=a_mi[i][1]){
					mivo=a[i][0]+a_mi[i][1]+a[i][unknow];
					if(flag[i]) mivo-=a[i][0];
				}
				else{
					mivo=a[i][0]+a_mi[i][2]+a[i][unknow];
					if(flag[i]) mivo-=a[i][0];
				}
			}
			else{
				mivo=a[i][0]+a[i][unknown]+a[i][unknow];
				if(flag[i]) mi-=a[i][0];
			}
			if(mi>mivo){
				mi=mivo;
				miid=i;
			}
		}
		vis[u]=true,vis[v]=true;
		if(e[i].w<=mi){
			ans+=e[i].w;
		}
		else if(mi>=0&&mi!=INT_MAX){
			ans+=mi;
			flag[miid]=true;
		}
		else ans+=e[i].w;
		cnt++;
		if(cnt==n-1) return ;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a_mi,0x3f,sizeof(a_mi));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]<a_mi[i][1]) a_mi[i][2]=a_mi[i][1],a_mi[i][1]=a[i][j];
			else if(a[i][j]<a_mi[i][2]) a_mi[i][2]=a[i][j];
		}
	}
	sort(e+1,e+1+m,cmp);
	krske();
	printf("%lld",ans);
	return 0;
}
