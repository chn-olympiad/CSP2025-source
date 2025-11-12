#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,mm=2e9,pos;
bool vi[10001];
vector<vector<pair<ll,ll> > >a(10001);
bool cmp1(pair<int,int>a,pair<int,int>b){
	return a.first<b.first;
}
ll dfs(){
	ll money=0;vi[pos]=1;
	priority_queue<pair<int,int> >q;
	queue<int>v;
	for(int i=1;i<n;i++) v.push(0);
	for(int i=0;i<a[pos].size();i++){
		q.push(a[pos][i]);
	}while(!q.empty()){
		cout<<q.top().first<<' '<<q.top().second<<endl;
		q.pop();
	}
	while(v.front()!=1){
		if(vi[q.top().second]) q.pop();
		else{
			int f=q.top().first,s=q.top().second;
			q.pop();
			money+=f;
			for(int i=0;i<a[s].size();i++){
				q.push(a[s][i]);
			}
			vi[s]=1;
			v.pop();
			v.push(1);
		}
	}
	return money;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({w,v});
		a[v].push_back({w,u});
		if(w<mm){
			mm=w;
			pos=u;
		}
	}
	for(int i=1;i<=k;i++){
		ll c,b[10005];
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>b[j];
		}
		for(int j=1;j<=n;j++){
			int vl[100001];
			memset(vl,0,sizeof vl);
			vl[j]++;
			for(int d=0;d<a[j].size();d++){
				vl[a[j][d].second]++;
				if(a[j][d].first>b[j]+b[a[j][d].second]+c){
					a[j][d].first=b[j]+b[a[j][d].second]+c;
					if(a[j][d].first<mm){
						mm=a[j][d].first;
						pos=j;
					}
				}
			}
			for(int d=1;d<=n;d++){
				if(!vl[d]){
					a[j].push_back({b[j]+b[d]+c,d}) ;
				}
				if(b[j]+b[d]+c<mm){
					mm=b[j]+b[d]+c;
					pos=j;
				}
			}
		}
	}
	ll mo=dfs();
	cout<<mo;
	return 0;
} 
