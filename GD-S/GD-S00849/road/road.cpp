#include<bits/stdc++.h>
#define vnode vector<node> 
typedef long long ll;
using namespace std; //³£Êý 5-10 
const ll N=1e4+100,oo=0x3f3f3f3f3f3f3f3f;
struct node{
	int u,v,w;
};
int n,m,k;
ll ans=oo;
ll cost[2][40],c[15];
vnode e,sete[2][35],ve[15];
vnode _;
int f[2*N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void Kruskal(const vnode &e,vnode &res){
	int eds=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=0;i<e.size();i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x^y){
			f[x]=y;
			res.push_back(e[i]);
		}
	}
}
void bin(const vnode &A,const vnode &B,vnode &res){
	int L=0,R=0;
	int Alen=A.size(),Blen=B.size(); 
	while(1){
		if(L<Alen&&(R==Blen||A[L].w<B[R].w))
			res.push_back(A[L]),L++;
		else
			res.push_back(B[R]),R++;
		if(L==Alen&&R==Blen) break;
	}
}
void solve(int id){
	int len=(k+id)/2;
	int tot=(1<<len);
	for(int i=0;i<=tot;i++){
		int eds=0;
		vnode E=e;
		for(int j=1;j<=len;j++)
			if(i>>(j-1)&1){
				vnode res;
				bin(E,ve[id*(k/2)+j],res);
				swap(E,res);
				cost[id][i]+=c[id*(k/2)+j];
			}
		Kruskal(E,sete[id][i]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w; 
		e.push_back({u,v,w});
	}
	sort(e.begin(),e.end(),cmp);
	_.clear();
	Kruskal(e,_);
	swap(e,_);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w; cin>>w;
			ve[i].push_back({n+i,j,w});
		}
		sort(ve[i].begin(),ve[i].end(),cmp);
	}
	solve(0);
	solve(1);
	int len1=k/2,len2=k-k/2;
	int tot1=(1<<len1),tot2=(1<<len2);
	for(int s1=0;s1<tot1;s1++){
		for(int s2=0;s2<tot2;s2++){
			vnode E;
			ll s=0;
			bin(sete[0][s1],sete[1][s2],E);
			_.clear();
			Kruskal(E,_);
			for(node v:_)
				s+=v.w;
			ans=min(ans,s+cost[0][s1]+cost[1][s2]);
		}
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
