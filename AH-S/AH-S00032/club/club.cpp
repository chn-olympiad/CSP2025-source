#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int T,n;
int a[N][3];
int mx[N],sc[N];
struct node{
	int v,id;
	friend bool operator <(const node x,const node y){
		return a[x.id][mx[x.id]]-a[x.id][sc[x.id]]>a[y.id][mx[y.id]]-a[y.id][sc[y.id]];
	}
};
priority_queue<node> q[3];
signed main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		for(int i=0;i<=2;i++){while(!q[i].empty()) q[i].pop();}
		cin>>n;
		for(int i=1;i<=n;i++){
			vector<pair<int,int>> tmp;
			for(int j=0;j<=2;j++){
				cin>>a[i][j];tmp.push_back({a[i][j],j});
			}
			sort(tmp.begin(),tmp.end());
			mx[i]=tmp[2].second,sc[i]=tmp[1].second;
		}
		for(int i=1;i<=n;i++){
			q[mx[i]].push({a[i][mx[i]],i});
			if(q[mx[i]].size()>n/2){
				auto tmp=q[mx[i]].top();q[mx[i]].pop();
				q[sc[tmp.id]].push({a[tmp.id][sc[tmp.id]],tmp.id});
			}
		}
		int ans=0;
		for(int t=0;t<=2;t++){
			while(!q[t].empty()){
				ans+=q[t].top().v;
				q[t].pop();
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
