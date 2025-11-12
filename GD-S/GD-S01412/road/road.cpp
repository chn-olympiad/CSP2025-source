#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+1e5;
ll n,m,k,ans=-1,c[N],fa[N],rk[N];
struct Node{
	int u,v,w;
}b[N];
int find(int u){
	if(fa[u]==u)return u;
	return fa[u]=find(fa[u]);
}
void uv(int u,int v){
	u=find(u);
	v=find(v);
	if(u==v){
		return;
	}
	if(rk[u]<rk[v])swap(u,v);
	if(rk[u]==rk[v]){
		rk[u]++;
	}
	else if(rk[u]>rk[v]){
		rk[v]=rk[u];
		rk[u]++;
	}
	fa[v]=u;
}
bool cmp(Node x,Node y){
	return x.w<y.w;
}
int main(){
	/*难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难难*/
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		c[i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	ll cnt=m;
	for(int i=1;i<=k;i++){
		cin>>c[i+n];
		for(int j=1;j<=n;j++){
			b[++cnt].u=i+n;
			b[cnt].v=j;
			cin>>b[cnt].w;
		}
	}
	sort(b+1,b+cnt+1,cmp);
	ll sum=0;
	for(int i=1;i<=cnt;i++){
		if(find(b[i].u)!=find(b[i].v)){
			sum+=b[i].w;
			uv(b[i].u,b[i].v);
		}
	}
	cout<<sum;
	return 0;
}

/*
7 9 0
1 2 999
1 3 6
2 3 999
2 5 0
3 4 3
3 7 5
5 7 2
5 6 1
6 7 666
*/
