#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define D long double
#define lbt(x) ((x)&(-(x)))
#define N 20004
struct node{
	int x,y,z,to;
}e[2000006],e2[1000006];int cnt,cnt2;
bool cmp(node a,node b){
	if(a.z==b.z){
		return a.to<b.to;
	}
	return a.z<b.z;
}
int a[11][N],b[11],fa[N],dep[N],to[N];
int getf(int x){
	if(x==fa[x])	return x;
	return (fa[x]=getf(fa[x]));
}
inline bool merge(int x,int y){
	x=getf(x);y=getf(y);
	if(x==y)	return 0;
	if(dep[x]<dep[y])	swap(x,y);
	fa[y]=x;dep[x]+=(dep[x]==dep[y]);
	return 1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y>>e[i].z;e[i].to=0;
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];e[++cnt]={i+n,j,a[i][j],(1<<(i-1))};
		}
	}
	for(int i=1;i<=n+k;i++)	fa[i]=i;
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int x=e[i].x,y=e[i].y;x=getf(x);y=getf(y);
		if(x==y)	continue;
		e2[++cnt2]=e[i];
		if(!e[i].to)	fa[x]=y;
	}
	ll mn=1e18;
	for(int s=0;s<(1<<k);s++){
		/*int zt=0;
		for(int i=1;i<=k;i++)if(!(s&(1<<(i-1)))){
			if(b[i]==0){
				zt=1;break;
			}
		}
		if(zt)	continue;*/
		ll sum=0;
		for(int i=1;i<=n+k;i++)	fa[i]=i,dep[i]=1;
		for(int i=1;i<=k;i++)if(s&(1<<(i-1))){
			sum+=b[i];
		}
		if(sum>=mn)	continue;
		for(int i=1;i<=cnt2;i++)if((s&(e2[i].to))||(e2[i].to==0)){
			int x=e2[i].x,y=e2[i].y;
			if(merge(x,y)){
				sum+=e2[i].z;
				/*if(s==1){
					cerr<<"NOW: "<<x<<" "<<y<<" : "<<e2[i].z<<"  "<<e2[i].to<<endl;
				}*/
				if(sum>=mn)	break;
			}
		}
		mn=min(mn,sum);
	}
	cout<<mn;
	return 0;
}
