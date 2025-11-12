#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1e4+20;
const long long inf=1e15+1e10;
int n , m , k;
vector<pair<int,int>> ed[maxn];
int nw[12];
long long Cnt[maxn] , C[maxn];
bool vis[maxn];
queue<int> q;
long long func(int s){
	long long ans=inf;
	for(int i=1;i <= n;i++)C[i]=inf;
	Cnt[s]=1;C[s]=0;
	q.push(s);
	while(q.size()){
		int x=q.front();q.pop();
		vis[x]=1;
		for(auto i:ed[x]){
			int y=0;
			if(i.first>n){
				y=nw[i.first%n];nw[i.first%n]=0;
			}
			if(C[i.first]>C[x]+i.second+y){
				C[i.first]=C[x]+i.second+y;
				Cnt[i.first]=Cnt[x]+(i.first>n);
				if(!vis[x])q.push(i.first);
			}
			if(Cnt[i.first]>=n)ans=min(ans,Cnt[i.first]);
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>> n >> m >> k;
	for(int i=1;i <= m;i++){
		int u , v , w;
		cin>> u >> v >> w;
		ed[u].push_back({v,w});
		ed[v].push_back({u,w});
	}
	for(int i=1;i <= k;i++){
		cin>> nw[i];
		int a;
		for(int j=1;j <= n;j++){
			cin>> a;
			ed[n+i].push_back({j,a});
			ed[j].push_back({n+i,a});
		}
	}
	cout<< func(1);
	return 0;
}
