#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e4+5;
struct node{int u,v;ll w;};
int n,m,k;
ll a[N];
int fa[N];
vector<node>e;
vector<int>_0;
int find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
bool cmp(node a,node b){return a.w<=b.w;}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int ui,vi;
		ll wi;
		cin>>ui>>vi>>wi;
		e.push_back({ui,vi,wi});
	}
	if(k!=0){
		for(int i=1;i<=k;++i){
			int ci;
			cin>>ci;
			if(ci!=0)return 0;
			for(int j=1;j<=n;++j){
				cin>>a[i];
				if(a[i]==0)_0.push_back(i);
			}
			for(auto i0:_0){
				for(int j=1;j<=n;++j){
					if(j!=i0){
						e.push_back({j,i0,a[i]});
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i)fa[i]=i;
	sort(e.begin(),e.end(),cmp);
	int cnt=0;
	ll ans=0;
	for(auto ei:e){
		int fx=find(ei.u);
		int fy=find(ei.v);
		if(fx!=fy){
			fa[ei.u]=fy;
			ans+=ei.w;
			cnt++;
		}
		if(cnt==n-1)break;
	}
	cout<<ans;
	return 0;
}