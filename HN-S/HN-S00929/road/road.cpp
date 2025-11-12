//15 21 3/4 min.16pts max.100pts
//138mb
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e4+5,M=1e6+5,K=10+5,E=2e6+5,P=2e4+5;
//for(;;)++rp;
int n,m,k,c[N],a[K][N],fa[P],t[K];
struct node{
	int u,v,w;
}e[E],ne[E],tmp[E];
mt19937 rnd(time(NULL)^random_device{}());
//++rp;
//struct n2{
//	int to,val;
//};
//vector<n2> nbr[N];
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void add(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		fa[x]=y;
	}
	return;
}
int kru(node t[],int tl){
//	cerr<<"$"<<endl;
	sort(t+1,t+1+tl,[](node a,node b){
		return a.w<b.w;
	});
//	cerr<<"&"<<tl<<endl;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	int ans=0,cnt=0;
	for(int i=1;i<=tl;i++){
//		cerr<<"^"<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
		if(find(t[i].u)!=find(t[i].v)){
			ans+=t[i].w;
			add(t[i].u,t[i].v);
			tmp[++cnt]=t[i];
//			cerr<<"#"<<endl;
		}
	}
//	cerr<<"%"<<ans<<endl;
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int ans=kru(e,m),cnt=n-1,sum=0;
	for(int i=1;i<=cnt;i++){
		e[i]=tmp[i];
	}
	for(int i=1;i<=k;i++){
		t[i]=i;
	}
	shuffle(t+1,t+1+k,rnd);
	for(int idx=1;idx<=k;idx++){
		int i=t[idx];
		for(int j=1;j<=cnt;j++){
			ne[j]=e[j];
		}
		for(int j=1;j<=n;j++){
			ne[j+cnt]={n+i,j,a[i][j]};
		}
		int t=kru(ne,cnt+n);
		if(t+c[i]<ans){
//			cerr<<"!"<<i<<endl;
			ans=c[i];
			sum+=t;
			cnt++;
			for(int j=1;j<=cnt;j++){
				e[j]=tmp[j];
//				cerr<<"@"<<e[j].u<<" "<<e[j].v<<" "<<e[j].w<<endl; 
			}
		}
	}
	cout<<ans+sum;
	return 0;
}
//k<=10, that's great!
//The machine I'm using is too slow!
//...
//This is wangboyue_740325@Luogu.
//Maybe I'll AFO this year.
//Thank you(?), OI.
