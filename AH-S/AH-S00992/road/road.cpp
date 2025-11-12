#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e18;
int n,m,k;
struct node{
	int to;
	ll cost;
};
vector<node>a[10025];
int c[15];
int fm[10025];
int fmv[10025]; 
bool flag[15];
queue<int> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	//init();
	for(int i=1;i<=m;i++){
		int x,y;
		ll z;
		cin>>x>>y>>z;
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		ll z;
		for(int j=1;j<=n;j++){
			cin>>z;
			a[n+i].push_back({j,z});
			a[j].push_back({n+i,z});
		}
	}
	q.push(1);
	//ll sum=0;
	while(!q.empty()){

		int u=q.front();
	//	cout<<"u:"<<" "<<u<<endl;
		q.pop();
		int sz=a[u].size();
		for(int i=0;i<sz;i++) {
			int v=a[u][i].to;
			ll num=a[u][i].cost;
			
			if(fm[v]==0){
				fm[v]=u;
				fmv[v]=num;
				if(u>n&&!flag[u-n]){
					fmv[v]+=c[u-n];
					flag[u-n]=1;
				}
				q.push(v);
			}
			else{
				if(u>n&&!flag[u-n]){
					num+=c[u-n];
					
				}
				if(num<fmv[v]){
					fmv[v]=num;//q.push(v);
					if(u>n&&!flag[u-n]){
					
					flag[u-n]=1;
				}
				}
				
			}
			//cout<<v<<" "<<fmv[v]<<endl;
		}
		
	}
	ll ans=0;
	for(int i=1;i<=n;i++) ans+=fmv[i];
	cout<<ans<<endl;
	return 0;
}
