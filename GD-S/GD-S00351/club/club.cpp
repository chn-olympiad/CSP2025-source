#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5;
ll T,n,ans;
struct node{
	ll w1,w2,w3;
}a[N+100];
vector<ll>v[5];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		v[1].clear(),v[2].clear(),v[3].clear();
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].w1>>a[i].w2>>a[i].w3;
			if(a[i].w1>a[i].w2&&a[i].w1>a[i].w3) v[1].push_back(i);
			else if(a[i].w2>a[i].w1&&a[i].w2>a[i].w3) v[2].push_back(i);
			else v[3].push_back(i);
			ans+=max(a[i].w1,max(a[i].w2,a[i].w3));
		}
		priority_queue<pair<ll,ll>>q;
		while(q.size()) q.pop();
		if(v[1].size()>n/2){
			ll len=v[1].size()-n/2;
			for(auto h:v[1]){
				q.push({min(a[h].w1-a[h].w2,a[h].w1-a[h].w3),h});
				while(q.size()>len) q.pop();
			}
		}
		if(v[2].size()>n/2){
			ll len=v[2].size()-n/2;
			for(auto h:v[2]){
				q.push({min(a[h].w2-a[h].w1,a[h].w2-a[h].w3),h});
				while(q.size()>len) q.pop();
			}
		}
		if(v[3].size()>n/2){
			ll len=v[3].size()-n/2;
			for(auto h:v[3]){
				q.push({min(a[h].w3-a[h].w2,a[h].w3-a[h].w1),h});
				while(q.size()>len) q.pop();
			}
		}
		while(q.size()){
			ans-=q.top().first;
			q.pop(); 
		}cout<<ans<<"\n";
	}
	return 0;
}/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
