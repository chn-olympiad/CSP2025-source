#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n;
struct node{
	int my,id;
	bool operator < (const node&A)const{
		if(my==A.my) return id<A.id;
		return my>A.my;
	}
};
vector<node> a[N];
int vis[N];
void solve(){
	int ans=0;
	set<pair<int,int>> st[4];
	for(int i=1;i<=n;i++){
		int id=a[i][0].id;
		int val=a[i][0].my-a[i][1].my;
		st[id].insert({val,i});
		ans+=a[i][0].my;
	}
	//cout<<"ans="<<ans<<"\n";
	// for(int i=1;i<=n;i++){
	// 	cout<<a[i][0].my<<" "<<a[i][1].my<<" "<<a[i][2].my<<"\n";
	// }
	while(1){
		//cout<<st[1].size()<<" "<<st[2].size()<<" "<<st[3].size()<<"\n";
		if(!(st[1].size()>n/2 || st[2].size()>n/2 || st[3].size()>n/2)){
			break;
		}
		int id;
		for(int i=1;i<=3;i++)
			if(st[i].size()>n/2){
				id=i;
				break;
			}
		//cout<<"id="<<id<<" size="<<st[id].size()<<"\n";
		int sz=st[id].size();
		auto it=st[id].begin();
		for(int i=1;i<=sz-n/2;i++){
			auto p=*it;
			it=st[id].erase(it);
			//cout<<"id="<<id<<" sz="<<st[id].size()<<"\n";
			ans-=p.first;
			int temp=p.second;
			vis[temp]++;
			//cout<<"temp="<<temp<<" "<<vis[temp]<<"\n";
			int nxt=a[temp][vis[temp]].my-a[temp][vis[temp]+1].my;
			st[a[temp][vis[temp]].id].insert({nxt,temp});
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int x;
				cin>>x;
				a[i].push_back({x,j});
			}
		}
		for(int i=1;i<=n;i++)
			sort(a[i].begin(),a[i].end());
		solve();
		for(int i=1;i<=n;i++)
			a[i].clear();
		fill(vis,vis+n+1,0);
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/