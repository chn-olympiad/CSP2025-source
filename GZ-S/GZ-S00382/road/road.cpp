//GZ-S00382 贵阳市第一中学 胡源宸 
#include<bits/stdc++.h>
#define ls 1>>1
#define rs 1>>1|1
using namespace std;
using ll=long long;
constexpr int N=1e4+30,M=1e7+10;
int n,m,k;
struct node{
	int u,v,len,next;
}a[M];
int w;
int f[N];
int pre[N],idx;
ll ans;
void add(int u,int v,int w){
	a[++idx]={u,v,w,pre[u]};
	pre[u]=idx;
	return;
}
bool cmp(node x,node y){
	return x.len<y.len;
}
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k+n;++i) f[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&w);
			if(j>=1){
				add(i+n,j,w);
				add(j,i+n,w);
			}
		}
	}
	sort(a+1,a+1+idx,cmp);
	for(int i=1;i<=idx;i++){
		int from=a[i].u,to=a[i].v;
		int ff=find(from),ft=find(to);
		if(ff!=ft){
			ans+=a[i].len;
			f[ff]=ft;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
