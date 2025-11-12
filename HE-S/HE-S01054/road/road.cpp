#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e4+5,M=1e6+5;;
long long n,m,k,f[N];
int c[12],a[12][N];
long long cnt,ans;
struct Node{
	int u,v,w;
}e[M];
bool cmp(Node x,Node y){
	return x.w<y.w;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	bool p=1;
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
			if(a[j][i] !=0) p=0;
		}
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+1+m,cmp);
	int x,y;
	if(k==0){
		for(int i=1;i<=m;i++){
			if(cnt==n-1) break;
			x=find(e[i].u );
			y=find(e[i].v );
			if(x==y) continue;
			f[x]=f[y];
			ans+=e[i].w;
			cnt++;
		}
		cout<<ans;
		return 0;
	}
	else if(p){
		cout<<0;
	}
	
	return 0;
}
