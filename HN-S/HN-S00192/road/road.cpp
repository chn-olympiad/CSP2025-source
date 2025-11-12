#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10;
int ans,q,n,m,k,u,v,w,c[N];
map<pair<int,int>,int> mp;
vector<int> a;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		if(u>v) swap(u,v);
		mp[{u,v}]=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&q);
		for(int j=1;j<=n;j++) scanf("%d",&c[j]);
		for(int j=1;j<n;j++)
		for(int l=j+1;l<=n;l++){
			if(mp[{j,l}]!=0) mp[{j,l}]=min(mp[{j,l}],q+c[j]+c[l]);
			else mp[{j,l}]=q+c[j]+c[l];
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++) a.push_back(it->second);
	sort(a.begin(),a.end());
	for(int i=0;i<=n-2;i++) ans+=a[i];
	cout<<ans;
	return 0;
}
