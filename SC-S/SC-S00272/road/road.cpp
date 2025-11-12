#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
#define ll long long
vector<pair<ll,ll> >G[1000001]; 
ll n,m,k;
ll val[1000001],p[N][N],vis[1000001],tim[N];
void prim(){
	priority_queue<pair<ll,ll> > q;
	q.push(make_pair(0,1));
	int sum=0,cnt=0;
	while(q.size()&&cnt<n){
		ll x=q.top().second;
		ll di=q.top().first;
	//	cout<<x<<" "<<di<<endl;
		q.pop();
		if(vis[x]){
			continue;
		}
		if(x>n){

			tim[x-n]=1;
		}else{
			cnt++;	
		}
		vis[x]=1;
		
		sum-=di;
		for(auto it:G[x]){
			ll d=it.second;
			ll y=it.first;
			if(y>n){
				
				if(!tim[y-n]){
					d+=val[y-n];
				}
			}
			if(!vis[y]){
				q.push(make_pair(-d,y));
			}
		}
	}
	cout<<sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		G[x].push_back(make_pair(y,z));
		G[y].push_back(make_pair(x,z));
	}
	ll suma=0,sumb=0;
	for(int i=1;i<=k;i++){
		cin>>val[i];
		suma+=val[i];
		for(int j=1;j<=n;j++){
			cin>>p[i][j];
			sumb+=p[i][j];
		}
	}
	if(suma==0&&sumb==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=k;i++){

		for(int j=1;j<=n;j++){
			G[i+n].push_back(make_pair(j,p[i][j]));
			G[j].push_back(make_pair(i+n,p[i][j]));

		}
	}



	
	
	
	prim();
	
	
	return 0;
}