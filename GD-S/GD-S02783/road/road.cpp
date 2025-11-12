#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10010],ans;
vector<pair<int,pair<int,int> > >a;
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		a.push_back({w,{u,v}}); 
	}
	if(k==0){
		sort(a.begin(),a.end());
		int cnt=0;
		for(int i=0;i<m;i++){
			if(cnt==n) break;
			if(find(a[i].second.first)!=find(a[i].second.second)){
				ans+=a[i].first;
				fa[a[i].second.second]=a[i].second.first;
				cnt++;
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<"0";
	return 0;
}
//Ren5Jie4Di4Ling5%
