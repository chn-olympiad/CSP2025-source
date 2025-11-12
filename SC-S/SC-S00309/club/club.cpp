#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL n,a[100005][2],cnt[4];
bool vis[100005];
struct node{
	LL val1,val2,t1,t2;
};
bool operator <(node p,node q){
	return (p.val1-p.val2)>(q.val1-q.val2);
}

void solve(){
	LL ans=0,x,y,z;cnt[1]=cnt[2]=cnt[3]=0;
	cin>>n;
	vector<node> g;
	for(int i=1;i<=n;i++){
		vis[i]=0;
		cin>>x>>y>>z;
		LL t1=1,t2=2,t3=3;
		if(x<z){
			swap(x,z);
			swap(t1,t2);
		}
		if(x<y){
			swap(x,y);
			swap(t1,t3);
		}
		if(y<z){
			swap(y,z);
			swap(t2,t3);
		}
		g.push_back({x-z,y-z,t1,t2});
		ans+=z;
	}
	sort(g.begin(),g.end());
	//cout<<ans<<"\n";
	for(int i=0;i<g.size();i++){
		node v=g[i];
		if(cnt[v.t1]<n/2){
			ans+=v.val1;
			cnt[v.t1]++;
		}else if(cnt[v.t2]<n/2){
			ans+=v.val2;
			cnt[v.t2]++;
		}
		//cout<<v.val1<<' '<<v.val2<<' '<<v.t1<<' '<<v.t2<<' '<<cnt[1]<<' '<<cnt[2]<<' '<<cnt[3]<<'\n';
	}
	
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	LL t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
1
2
2 3 8
4 4 8
1
4
4 2 1
3 2 4
5 3 4
3 5 1
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
*/