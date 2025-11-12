#include<bits/stdc++.h>
using namespace std; //最小生成树 
const int N=10005,M=2000005;
long long n,m,k,u,v,w,c[15],a[15][N],cnt,fa[N];
long long ans;
struct size{
	long long u,v,w;
}s[M];
bool cmp(size x,size y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		s[i].u=u;
		s[i].v=v;
		s[i].w=w;
	}
	int t=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			t++;
			cin>>a[i][j];
			s[t].u=i;
			s[t].v=j;
			s[t].w=a[i][j];
		}
	}
	sort(s+1,s+t+1,cmp);
	for(int i=1;i<=t;i++){
		if(fa[s[i].u]!=fa[s[i].v]){
			ans+=s[i].w;
			fa[s[i].u]=fa[s[i].v]=min(fa[s[i].u],fa[s[i].u]);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
