#include<bits/stdc++.h>
#define all(op) op.begin(),op.end() 
using namespace std;
using ll=long long;
const int inf=1e9+7;
const ll INF=1e18+7;
void solve(){
	int n;cin>>n;
	vector<vector<pair<int,int>>> a(n+1,vector<pair<int,int>>(4));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j].first;
			a[i][j].second=j;
		}
		sort(a[i].begin()+1,a[i].end(),[&](pair<int,int> x,pair<int,int> y){
			return x.first>y.first;
		});
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=3;j++)cerr<<a[i][j].first<<" "<<a[i][j].second<<" "; 
//		cerr<<"\n";
//	}	
	
	vector<priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>> q(4);
	for(int i=1;i<=n;i++){
		int p=a[i][1].first-a[i][2].first,j=a[i][1].second;
		if(q[j].size()<n/2)q[j].push({p,{i,1}});
		else{
			if(p>q[j].top().first){
				auto u=q[j].top().second.first,v=q[j].top().second.second,lp=a[u][v+1].first-a[u][v+2].first;
				q[a[u][v+1].second].push({lp,{u,v+1}});
				q[j].pop();
				q[j].push({p,{i,1}});
			}else{
				p=a[i][2].first-a[i][3].first;
				q[a[i][2].second].push({p,{i,2}});	
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=3;i++){
//		cerr<<i<<"-------------\n";
		while(!q[i].empty()){
//			cerr<<q[i].top().second.first<<" "<<q[i].top().second.second<<"\n";
//			cerr<<ans<<" "<<a[q[i].top().second.first][q[i].top().second.second].first<<"---------\n";
			ans+=a[q[i].top().second.first][q[i].top().second.second].first;
			q[i].pop();
		}
	}
	cout<<ans<<"\n";
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
//    freopen("club5.in","r",stdin);
//    freopen("test.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
     cin>>T;
    while(T--)solve();
}
/*

1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

147325



*/
