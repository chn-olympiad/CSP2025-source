#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e4+7;
ll n,m,k,c[11][N],cc[11],f[N],ans;
map<pair<ll,ll>,ll>mp;
vector<int>v[N];
vector<pair<int,int> >v2;
bool cmp(pair<int,int> s1,pair<int,int> s2){
	return mp[{s1.first,s1.second}]<mp[{s2.first,s2.second}];
}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]); 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		if(z==0)z=-1;
		if(mp[{x,y}]==0){
			v[x].push_back(y);
			v[y].push_back(x);
			mp[{x,y}]=mp[{y,x}]=z;
			v2.push_back({x,y});
		}
		else mp[{x,y}]=mp[{y,x}]=min(mp[{x,y}],z);
	}
	for(int i=1;i<=k;i++){
		cin>>cc[i];
		for(int j=1;j<=n;j++)cin>>c[i][j];
	}
	sort(v2.begin(),v2.end(),cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=0;i<v2.size();i++){
		int x=v2[i].first,y=v2[i].second;
		if(f[x]==f[y])continue;
		ans+=mp[{x,y}];
		if(mp[{x,y}]==0)ans++;
		f[find(x)]=find(y);
	} 
	cout<<ans;
	return 0;
} /*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
