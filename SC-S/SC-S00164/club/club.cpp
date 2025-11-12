#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,sum=0;
		cin>>n;
		vector<vector<int>>v(n+1,vector<int>(3));
		vector<int>cnt(3,0);
		priority_queue<int,vector<int>,greater<int>> q[3];
		for(int i=1;i<=n;i++)
			cin>>v[i][0]>>v[i][1]>>v[i][2];
		for(int i=1;i<=n;i++){
			int idx=max_element(v[i].begin(),v[i].end())-v[i].begin();
			int mn=*min_element(v[i].begin(),v[i].end());
			int d=v[i][idx]-(v[i][0]^v[i][1]^v[i][2]^v[i][idx]^mn);
			q[idx].push(d);
			sum+=v[i][idx];
			cnt[idx]++;
		}
		for(int i=0;i<3;i++){
			if(cnt[i]<=n/2)
				continue;
			while(q[i].size()>n/2){
				sum-=q[i].top();
				q[i].pop();
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}