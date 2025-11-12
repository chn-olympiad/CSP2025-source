#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000005;
int n,m,k,cnt,snt,ans;
int fa[N],ww[11][10005];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}//BCJ SETTING
struct node{int u,v,w;}s[3*N],s2[3*N],s3[3*N];
bool cmp(node x1,node x2){return x1.w<x2.w;}
//STRUCTION SETTING
int work(int ask){
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=snt;i++){
		s3[i].u=s2[i].u,
		s3[i].v=s2[i].v,
		s3[i].w=s2[i].w;
	}
	sort(s3+1,s3+snt+1,cmp);
	for(int i=1;i<=snt;i++){
		int fr=s3[i].u,to=s3[i].v;
		if(find(fr)==find(to))continue;
		fa[find(fr)]=fa[find(to)];
		ask+=s3[i].w;
	}
	return ask;
}//1-n city   n+1-n+k village
void dfs(int x,int sum){
	if(x>k)return;
	sum+=ww[x][0];
	for(int i=1;i<=n;i++){
		s2[++snt].u=i;
		s2[snt].v=n+x;
		s2[snt].w=ww[x][i];
	}
	ans=min(ans,work(sum));
	
	dfs(x+1,sum);
	
	sum-=ww[x][0];
	snt-=n;
	ans=min(ans,work(sum));
	dfs(x+1,sum);
	
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++)cin>>s[i].u>>s[i].v>>s[i].w;
	for(int j=1;j<=k;j++)for(int i=0;i<=n;i++)cin>>ww[j][i];
	sort(s+1,s+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fr=s[i].u,to=s[i].v;
		if(find(fr)==find(to))continue;
		fa[find(fr)]=fa[find(to)];
		ans+=s[i].w;
		s2[++snt].u=s[i].u;
		s2[snt].v=s[i].v;
		s2[snt].w=s[i].w;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}