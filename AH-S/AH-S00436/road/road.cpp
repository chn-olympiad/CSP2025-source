#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define F std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct pp{
	ll u,v,w;
};
bool cmp(pp a,pp b){
	return a.w<b.w;
}
int main(void){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	F;
	ll n,m,k,u,v,w,i,j,l,d,h[15][10005],cnt[10005]{0},s,hhh[15],mmn;
	map<pair<ll,ll>,ll>mp,mpp;
	cin>>n>>m>>k;
	for(i=1;i<=n;++i)
		for(j=i;j<=n;++j)mp[{i,j}]=INT_MAX;
	for(i=0;i<m;++i)cin>>u>>v>>w,mp[{min(u,v),max(u,v)}]=w;
	for(i=0,mmn=LLONG_MAX;i<k;++i){
		cin>>hhh[i+1];
		for(j=1;j<=n;++j)cin>>h[i+1][j];
	}
	for(i=(1<<k)-1;i>-1;--i){
		memset(cnt,0,sizeof(cnt));
		mpp=mp,s=0;
		for(j=0;j<k;++j)
			if((i>>j)&1){
				s+=hhh[j+1];
				for(int xx=1;xx<=n;++xx)
					for(int yy=xx+1;yy<=n;++yy)mpp[{xx,yy}]=min(mpp[{xx,yy}],h[j+1][xx]+h[j+1][yy]);
			}
		vector<pp> z;
		for(auto it:mpp)z.push_back({it.first.first,it.first.second,it.second});
		sort(z.begin(),z.end(),cmp);
		for(j=l=0;j<z.size()&&l<n-1;++j){
			if(cnt[z[j].u]==0||cnt[z[j].v]==0){
				cnt[z[j].u]=cnt[z[j].v]=1;
				s+=z[j].w,++l;
			}
		}
		mmn=min(mmn,s);
	}
	cout<<mmn<<"\n";
	return 0;
}
