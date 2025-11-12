#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,c[15],a[15][N];
int f[N];
struct node{
	int u,v,w;
};
bool operator<(node x,node y){return x.w>y.w;}
priority_queue<node> s;
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		s.push({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++) f[i]=i;
	if(k==0){
		long long cnt=0,ans=0;
		while(cnt<n-1){
			node x=s.top();s.pop();
			int ru=find(x.u),rv=find(x.v);
			if(ru!=rv){
				f[ru]=rv;
				ans+=x.w;
				cnt++;
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
}