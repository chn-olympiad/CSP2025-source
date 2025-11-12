#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k,sum=0,num=1;
	cin>>n>>m>>k;
	vector<vector<pair<int,int>>> t;
	t.resize(10000);
	for(int i=0;i<m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		t[u].push_back(pair<int,int>(w,v));
		t[v].push_back(pair<int,int>(w,u));
	}
	set<int> s;
	int mp[n+1];
	for(int i=0;i<=n;++i)mp[i]=0x7f7f7f7f;
	queue<int> q;
	q.push(1);
	s.insert(1);
	mp[1]=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		sort(t[now].begin(),t[now].end());
		for(auto &a:t[now]){
			if(!s.count(a.second)){
				s.insert(a.second);
				q.push(a.second);
				sum+=a.first;
				mp[a.second]=a.first;
				num++;
			}else{
				if(a.second==1 or mp[now]==a.first)continue;
				if(mp[a.second]==0x7f7f7f7f) sum+=a.first,mp[a.second]=a.first;
				if(a.first<mp[a.second]) sum-=mp[a.second]-a.first,mp[a.second]=a.first;
			}
		}
	}
	cout<<sum;
	return 0;
}
