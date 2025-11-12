#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e6+10;
const int N=1e4+10;
int fa[N];
struct Node{
	int u, v, w;
}a[M+10*N];
bool cmp(Node a1, Node a2){
	return a1.w<a2.w;
}
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int dis[15][N];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d", &a[i].u, &a[i].v, &a[i].w);
	}
	for(int i=1;i<=k;i++){
		int c;
		scanf("%d", &c);
		for(int j=1;j<=n;j++){
			scanf("%d", &dis[i][j]);
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(a+1, a+m+1, cmp);
		int cnt=0;
		ll ans=0;
		for(int i=1;i<=m;i++){
			int x=a[i].u, y=a[i].v;
			int fx=find(x), fy=find(y);
			//cout<<x<<" "<<y<<" "<<a[i].w<<endl;
			//cout<<fx<<" "<<fy<<endl;
			if(fx==fy) continue;
			cnt++;
			fa[fx]=fy;
			ans+=a[i].w;
			//cout<<ans<<endl;
			if(cnt==n-1) break;
		}
		printf("%lld", ans);
	}
	else printf("0");
	return 0;
}