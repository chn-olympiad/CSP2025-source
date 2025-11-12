#include<bits/stdc++.h>
using namespace std;
const int mx=2e6+8;
#define ll long long
int fa[mx];
struct node{
	int u,v,w;
}g[mx];
bool cmp(node a,node b){
	return a.w<b.w;
}

int _f(int a){
	if(a==fa[a])return fa[a];
	else a=(_f(fa[a]));
	return a;
}
void _un(int a,int b){
	fa[_f(a)]=fa[_f(b)];
}
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
	}
	int num=n;
	for(int i=1;i<=k;i++){
		int c;
		scanf("%d",&c);
		if(c==0){
				n++;
			for(int i=1;i<=num;i++){
				m++;
				g[m].u=n,g[m].v=i;
				scanf("%d",&g[m].w);
			}
		}
		else {
			int f;
			for(int i=1;i<=n;i++){
				scanf("%d",&f);
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(g+1,g+m+1,cmp);
	int cnt=0;
	ll ans=0;
	for(int i=1;i<=m;i++){
		int u=g[i].u,v=g[i].v;
		if(_f(u)==_f(v))continue;
		else {
			cnt++;
			ans+=g[i].w;
			_un(u,v);
		}
		if(cnt==n-1){
			printf("%lld",ans);
			return;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t=1;
	//scanf("%d",&t);
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

