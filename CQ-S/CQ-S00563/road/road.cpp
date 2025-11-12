#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,u,v,w,f[20005],ans,Size[20005],Sum;
struct edge{ ll u,v,w,opt; }; vector<edge> Ans,G,Tr;
bool cmp(edge a,edge b){ return a.w<b.w; }
struct State{
	int cnt; ll ans;
	vector<edge> E;
}s[15];
struct Town{ ll c,a[10005],ans; }T[15];
bool cmp2(Town a,Town b){ return a.ans<b.ans; }
int find(int x){ return f[x]==x?x:f[x]=find(f[x]); }
bool merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		if(Size[fx]>Size[fy]) swap(fx,fy);
		f[fx]=fy,Size[fy]+=Size[fx];
		return true;
	} return false;
}
void Kruskal(int n,vector<edge> E){
	memset(f,0,sizeof(f)),iota(f+1,f+n+k+1,1),fill(Size+1,Size+n+k+1,1);
	sort(E.begin(),E.end(),cmp); int cnt=0; ans=0; Ans.clear();
	for(edge e:E){
		ll u=e.u,v=e.v,w=e.w;
		if(merge(u,v)){
			ans+=w,cnt++;
			if(e.opt==1) Ans.push_back(e);
			if(e.opt==0) Tr.push_back(e);
		}
		if(cnt==n-1) return;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++) cin >> u >> v >> w,
		G.push_back({u,v,w,0});
	Kruskal(n,G),s[0]={n,ans,Tr};
//	for(int i=1;i<=k;i++){
//		cin >> T[i].c; vector<edge> now=G; 
//		for(int j=1;j<=n;j++) cin >> T[i].a[j],now.push_back({n+1,j,T[i].a[j],1});
//		Kruskal(n+1,now),T[i].ans=ans+T[i].c;
//	} sort(T+1,T+k+1,cmp2);
	for(int i=1;i<=k;i++){
		cin >> T[i].c; ll sum=T[i].c;
		for(int j=1;j<=n;j++) cin >> T[i].a[j],sum+=T[i].a[j];
		T[i].ans=sum;
	} sort(T+1,T+k+1,cmp2);
	for(int i=1;i<=k;i++){
		vector<edge> now=s[i-1].E; int Id=s[i-1].cnt+1;
		for(int j=1;j<=n;j++) now.push_back({Id,j,T[i].a[j],1});
		for(edge e:Tr) now.push_back(e);
		Kruskal(s[i-1].cnt+1,now);
		s[i]={s[i-1].cnt+1,ans+Sum+T[i].c,Ans};
		if(ans+Sum+T[i].c>s[i-1].ans) s[i]=s[i-1]; 
		else Sum+=T[i].c;
//		cout << ans << '\n';
	} cout << s[k].ans;
	return 0;
}
/*
这个人怎么T2调这么久呢
啊，大概就是，想她了吧
zlxr我真的好好好喜欢你 
“晨观升日暮观霞，行也思卿，坐也思卿” 
“春赏百花冬赏雪，醒也思卿，梦也思卿”
*/
