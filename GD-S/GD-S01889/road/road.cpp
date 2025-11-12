#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=1e6+10;
struct node{
	ll u,v,w;
}l[4*N];
ll n,m,k,fa[N],id[N],nn,ans,b[N];
ll c[20],a[20][N];
bool cmp(ll x,ll y){
	return l[x].w<l[y].w;
}
void init(){
	for(int i=1;i<=10005;i++){
		fa[i]=i;
	}
	for(int i=1;i<N;i++) id[i]=i;
}
ll find(ll x){
	if(fa[x]==x) return x;
	return find(fa[x]);
}
ll kustra(ll p){
	sort(id+1,id+p+1,cmp);
	ll res=0;
	for(int i=1;i<=p;i++){
		ll x=l[id[i]].u,y=l[id[i]].v,w=l[id[i]].w;
		x=find(x);
		y=find(y);
		if(x==y) continue;
		res+=w;
		fa[x]=y; 
	}
	return res;
}
bool check(){
	for(int i=1;i<n;i++){
		if(find(i)!=find(i+1)) return false;
	}
	return true;
}
ll count(){
	ll res=0,len=m;
	for(int i=1;i<=k;i++){
		if(b[i]==1){
			res+=c[i];
			for(int j=1;j<=n;j++){
				len++;
				l[len].u=n+i;
				l[len].v=j;
				l[len].w=a[i][j];
			}
		}
	}
	init();
	ll sum=kustra(len)+res;
	return sum;
}
void dfs(ll u){
	if(u>k){
		ans=min(ans,count());
		return ;
	}
	b[u]=0;
	dfs(u+1);
	b[u]=1;
	dfs(u+1);
}
bool check1(){
	for(int i=1;i<=k;i++){
		if(c[i]!=0) return false;
		ll fl=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]==0){
				fl=1;
				break;
			}
		}
		if(fl==0) return false;
	}
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	nn=n;
	for(int i=1;i<=m;i++){
		cin>>l[i].u>>l[i].v>>l[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		init();
		cout<<kustra(m);
		return 0;
	}
	else if(check1()==true){
		queue<ll> q;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==0){
					q.push(j);
				}
			}
			while(!q.empty()){
				ll u=q.front();
				q.pop();
				m++;
				for(int j=1;j<=n;j++){
					l[m].u=u;
					l[m].v=j;
					l[m].w=a[i][j];
				}
			}
		}
		init();
		cout<<kustra(m);
		return 0;
	}
	else{
		ans=INT_MAX;
		dfs(1);
		cout<<ans;
		return 0;
	}
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 8 2 4
100 1 3 2 4
*/
