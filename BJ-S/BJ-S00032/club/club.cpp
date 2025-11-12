#include<bits/stdc++.h>
#define int long long
using namespace std;
using Pair=pair<int,int>;
constexpr int N=1e5+5,MAX=0x3fff'ffff'ffff'ffff;
int n; Pair a[N][5];
struct Val{
	int val,id,rnk;
	friend bool operator<(const Val &a,const Val &b){return (a.val<b.val);}
};
priority_queue<Val> pq[4];
void Init(int n){
	for(int i=1;i<=n;i++){
		for(auto x:{1,2,3}) a[i][x]={0,0};
		a[i][4]={-MAX,0};
	}
	for(auto x:{1,2,3}) while(!pq[x].empty()) pq[x].pop();
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T; cin>>T;
	for(int z=1;z<=T;z++){
		cin>>n; Init(n);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(auto x:{1,2,3}) cin>>a[i][x].first,a[i][x].second=x;
			sort(a[i]+1,a[i]+4,greater<Pair>());
			int tmp=a[i][1].second;
			pq[tmp].push({a[i][2].first-a[i][1].first,i,2}),ans+=a[i][1].first;
			if(pq[tmp].size()>n/2){
				auto [delta,id,rnk]=pq[tmp].top(); pq[tmp].pop();
				ans+=delta; pq[a[id][rnk].second].push({a[id][rnk+1].first-a[id][rnk].first,id,rnk+1});
			}
		}
		cout<<ans<<'\n';
	}
}