#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+100;
int n,m;
int a[N],ans;
vector<int> g[N];
int c[N];
struct node{
	int l,r;
};
vector<node> e;
unordered_map<int,int> mp;
int el,er;
bool cmp(node x,node y){
	if(x.r!=y.r)
	return x.r<y.r;
	return x.l<y.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];	
	c[i]=c[i-1]^a[i];
	g[c[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int k=m^c[i-1];
		if(g[k].size()&&g[k][g[k].size()-1]>=i){
			int id=g[k][lower_bound(g[k].begin(),g[k].end(),i)-g[k].begin()];
			e.push_back({i,id});
		}
	}
	sort(e.begin(),e.end(),cmp);
	el=er=-1;
	for(auto i:e){
		int l=i.l,r=i.r;
		if(r>er&&l>el&&l>er){
			ans++;
			er=r;el=l;
		}
	}
	cout<<ans;
	return 0;
}
