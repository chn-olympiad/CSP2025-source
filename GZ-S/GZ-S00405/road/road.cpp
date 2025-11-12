#include<bits/stdc++.h>//GZ-S00405 裘滨溪 贵州省丘成桐少年班 
#include<set>
using namespace std;
struct mystrcut1{
	int val,idx;
};
vector<mystrcut1> a[10010];
bool f[10010];
struct mystruct{
	int val,idx;
	bool operator<(const mystruct aa)const{
		return val<aa.val;
	}
};
set<mystruct> s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({w,v});
		a[v].push_back({w,u});
	}
	f[1]=true;
	for(int i=0;i<a[1].size();i++){
		s.insert({a[1][i].val,a[1][i].idx});
	}
	int ans=0;
	for(int i=1;i<n;i++){
		mystruct idx=*s.begin();
		s.erase(s.begin());
		f[idx.idx]=true;
		ans+=idx.val;
		for(int j=0;j<a[idx.idx].size();j++){
			if(!f[a[idx.idx][j].idx]){
				s.insert({a[idx.idx][j].val,a[idx.idx][j].idx});
			}
		}
	}
	cout<<ans;
	return 0;
}
