#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k;
vector<pair<int,long long>> v[N];
long long c[N],a[11][N];
bool flagA=true;
struct node{
	long long a,b,w;
}e[M];
bool cmp(node x,node y){
	return x.w<y.w;
}
int fa[N];
int find(int x){
	return x==fa[x]? x:fa[x]=find(fa[x]);
}
void he(int x,int y){
	int fx=find(x);
	fa[fx]=find(y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long u,t,w;
		cin>>u>>t>>w;
		v[u].push_back(make_pair(t,w));
		v[t].push_back(make_pair(u,w));
		e[i].a=u;
		e[i].b=t;
		e[i].w=w;
	}
	if(k==0){
		long long ans=0;
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=m;i++){
			int a=e[i].a,b=e[i].b;
//			cout<<a<<" "<<b<<" ";
			if(find(fa[a])==find(fa[b])) continue;
//			cout<<find(fa[a])<<" "<<find(fa[b])<<endl;
			ans+=e[i].w;
			he(a,b);
		}
		cout<<ans;
		return 0; 
	} 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flagA=false; 
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0) flagA=false;
		}
	}
	if(flagA){
		cout<<0;
		return 0;
	}
	return 0;
} 
