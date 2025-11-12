#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w,cnt,ca,c[15],a[10005][15];
struct node{
	int u,v,w;
}e[1200005];
bool cmp(node a,node b){
	return a.w<b.w;
}
int fa[11005],num;
long long ans,anss;
bool f[15];
int find(int x){
	if(x==fa[x]){
		return x;
	}
	else{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
long long kruscal(){
	int sum=0;
	for(register int i=1;i<=cnt;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			sum++;
			anss+=e[i].w;
		}
		if(sum==num-1){
			break; 
		}
	}
	return anss;
}
void solve(){
	num=n;
	anss=0;
	for(register int i=1;i<=k;i++){
		if(f[i]){
			num++;
			anss+=c[i];
			for(register int j=1;j<=n;j++){
				e[++cnt].u=i+n;
				e[cnt].v=j;
				e[cnt].w=a[j][i];
			}
		}
	}
	for(register int i=1;i<=num;i++){
		fa[i]=i;
	}
	sort(e+1,e+cnt+1,cmp);
	ans=min(ans,kruscal());
}
void dfs(int x,int pos){
	if(x==k){
		cnt=m;
		for(register int i=1;i<=k;i++){
			f[i]=0;
			if(pos>>(i-1)&1){
				f[i]=1;
			}	
		}
		ca++;
		solve();
		return ;
	}
	dfs(x+1,pos<<1);
	dfs(x+1,pos<<1|1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(register int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	int flag=1;
	for(register int i=1;i<=k;i++){
		cin>>c[i];
		if(!c[i]){
			flag=0;
		}
		for(register int j=1;j<=n;j++){
			cin>>a[j][i];
			if(a[j][i]){
				flag=1;
			}
		}
	}
	if(!flag){
		cout<<"0"<<'\n';
		return 0; 
	}
	cnt=m;
	ans=5e18;
	dfs(0,0);
	cout<<ans<<'\n';
	return 0;
}
