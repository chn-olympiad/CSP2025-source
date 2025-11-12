#include<bits/stdc++.h>
#define int long long

using namespace std;

vector<pair<int,int> > road[10100];
vector<pair<int,int> > tree_r[10100];
vector<int> add_point;

int n,m,k,u,v,w,ans;
int county[10004][12],c[12];
bool book[10100],sum[13];

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q; 

int build(){
	
	for(int i=1;i<=n+40;i++)
		for(auto j:road[i])
			tree_r[i].emplace_back(j);
			
	q.push(make_pair(0,1));
	
	int retu=0;
	
	while(!q.empty()){
		auto new_r=q.top();
		q.pop();
		if(!book[new_r.second]){
			book[new_r.second]=true;
			retu+=new_r.first;
			for(auto will_r:tree_r[new_r.second])
				if(!book[will_r.first])
					q.push(make_pair(will_r.second,will_r.first));
			
//			cout<<new_r.second<<" "<<new_r.first<<endl; 
		} 
	}
	
	for(int i=1;i<=n+40;i++){
		book[i]=false;
		while(!tree_r[i].empty())
			tree_r[i].pop_back();
	}
	
	return retu;
}

int i_insert(int id){
	
	tree_r[id+n].emplace_back(make_pair(id+n+20,c[id]));
	tree_r[id+n+20].emplace_back(make_pair(id+n,0));
	
//	for(int k:add_point){
//		tree_r[id+n+20].emplace_back(make_pair(k+20+n,0));            //猜结论内 
//		tree_r[k+n+20].emplace_back(make_pair(id+20+n,0));            //猜结论内 
//	} 
	
	for(int i=1;i<=n;i++){
		tree_r[i].emplace_back(make_pair(id+n,county[i][id]));
		tree_r[id+n].emplace_back(make_pair(i,county[i][id]));
	}
	
	return build();
}

void real_insert(int id){
	road[id+n].emplace_back(make_pair(id+n+20,c[id]));
	
	for(int i=1;i<=n;i++){
		road[i].emplace_back(make_pair(id+n,county[i][id]));
		road[id+n].emplace_back(make_pair(i,county[i][id]));
	}
}

signed main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		road[u].emplace_back(make_pair(v,w));
		road[v].emplace_back(make_pair(u,w));
	}
	
	
	int op=k;
	while(op){
		int ll=rand()%k+1;
		if(!sum[ll]){
			sum[ll]=true;
			op--;
			add_point.emplace_back(ll);
		}
	}
	
	for(int i:add_point){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>county[j][i];
	}
	
	for(int i=0;i<=k;i++){
//		cout<<"**********************\n"<<i<<endl;
		if(i==0){
			ans=build();
//			cout<<ans<<endl;
		}
		else{
			int soon=i_insert(i);
			if(soon<=ans)
				real_insert(i),ans=soon,add_point.push_back(i);
//			cout<<soon<<endl;
		}
//		cout<<endl<<endl;
	}
	
	cout<<ans<<endl;
	
	return 0;
} 
