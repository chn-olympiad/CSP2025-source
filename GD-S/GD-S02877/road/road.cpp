#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
const int N=1e4+5,M=2e6+5;
ll n,m,k,idx,c[15],ans1,ans2,fa[N];
struct node{
	ll u,v,w;
}e[M];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
vector<pair<ll,ll> >ne[N],ve[15];
void kru(ll &sum,ll al,bool f){
	sort(e+1,e+idx+1,cmp);
	for(int i=1,cnt=0;i<=idx&&cnt<al-1;i++){
		if(find(e[i].u)!=find(e[i].v)){
			fa[find(e[i].u)]=find(e[i].v),sum+=e[i].w,cnt++;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll u,v,w,i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[++idx]={u,v,w};
	}
	bool fl=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1,w;j<=n;j++)
			cin>>w, ve[i].push_back({j,w});
		if(c[i]!=0) fl=1;
	}
	if(k==0) {
		for(int i=1;i<=n;i++) fa[i]=i;
		kru(ans1,n,0),cout<<ans1;
	}
	else if(fl==0){
		//特殊性质A
		//可以免费改造 且一个村子 可以连出来一条 边权为0的 边
		//我可以用别的东西 把村子 和那个点 直接连起来 ?
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=k;i++){
			for(auto it:ve[i]){
				if(it.second==0) fa[find(n+i)]=find(it.first);
			} 
		}
		for(int i=1;i<=k;i++){
			for(auto it:ve[i]){
				if(it.second!=0)
				e[++idx]={find(n+i),it.first,it.second};
			} 
		}
		kru(ans1,n+k,0);
		cout<<ans1;
	}else{
		for(int i=1;i<=n;i++) fa[i]=i;
		kru(ans1,n,0),cout<<ans1;
	}
	return 0;
}
