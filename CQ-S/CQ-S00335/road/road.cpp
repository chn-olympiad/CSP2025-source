#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define x first
#define y second
using namespace std;
ll n,m,k,dis,flag=0;
bool vis[10005];
struct opzc{
	int u,v,w;
}a[1000005];
vector<vector<pair<int,int> > > pz(10005);
bool cmp(opzc a,opzc b){
	return a.w<b.w;
}
void dfs(ll x,ll mb){
	if(flag==1)return ;
	for(auto i:pz[x]){
		if(vis[i.x]==0){
			if(i.x==mb){
				flag=1;
				return;
			}
			vis[i.x]=1;
			dfs(i.x,mb);
			vis[i.x]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>a[i].u>>a[i].v>>a[i].w;;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;++i){
		memset(vis,0,sizeof vis);
		vis[a[i].u]=1;
		flag=0;
		dfs(a[i].u,a[i].v);
		if(flag==0){
			pz[a[i].u].push_back({a[i].v,a[i].w});
			pz[a[i].v].push_back({a[i].u,a[i].w});
			dis+=a[i].w;
		}
	}
	cout<<dis<<"\n";
	



	return 0;
}

