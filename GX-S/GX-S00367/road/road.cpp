#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+1;
const int maxm=1e6+1;
int n,m,k;
int c[11],a[11][maxn],fa[maxn];
struct node{
	int u,v,w,id;
}b[maxn];
void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}
int find(int x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
}
void merge(int x,int y){
	if(fa[x]!=fa[y])fa[x]=fa[y];
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++){
		b[i].id=i;
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		if(m<=n-1){
			int add=0;
			for(int i=1;i<=m;i++)add+=b[i].w;
			cout<<add;
		}else{
			sort(b+1,b+1+m,cmp);
			int cnt=0;
			int res=0;
			for(int i=1;i<=m;i++){
				if(cnt==n-1)break;
				if(find(b[i].u)==find(b[i].v))continue;
				merge(b[i].u,b[i].v);
				res+=b[i].w;
				cnt++;
			}
			cout<<res;
		}
	}else cout<<-1;
	return 0;
}
