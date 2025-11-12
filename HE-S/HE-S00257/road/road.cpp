#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+100,M=1e6+100;
int n,m,k;
int a[10][N],ak[10];
int f[N];
int find(int x){
	if(f[x]==x) return f[x];
	return f[x]=find(f[x]);
}
int id=0;
struct re{
	int u,v,w;
}edge[M];
bool cmp(re a,re b){
	return a.w<b.w;
}
void add(int a,int b,int c){
	edge[++id].u=a;
	edge[id].v=b;
	edge[id].w=c;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(edge+1,edge+1+n,cmp);
	for(int i=1;i<=k;i++){
		cin>>ak[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0) add(i,j,0);
		}
	}
	int sum=0,ans=0;
	for(int i=1;i<=id;i++){
		int a=edge[i].u,b=edge[i].v;
		if(find(a)!=find(b)){
			ans+=edge[i].w;
			sum++;
			f[find(a)]=find(b);
		}
		if(sum==n-1) break;
	}
	cout<<ans;
	return 0;
}
