#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>

const int N=1e5+5;
int a[N],b[N],c[N];
int ans,n,siz[3],bel[N];
priority_queue<pii> qp[3];

void solve(){
	for(int i=0;i<3;i++) while(!qp[i].empty()) qp[i].pop();
	for(int i=0;i<3;i++) siz[i]=0;
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=n;i++){
		if(a[i]==max({a[i],b[i],c[i]})){
			qp[0].push({b[i]-a[i],i});
			qp[0].push({c[i]-a[i],i});
			siz[0]++;bel[i]=0;
		}
		else if(b[i]==max({a[i],b[i],c[i]})){
			qp[1].push({a[i]-b[i],i});
			qp[1].push({c[i]-b[i],i});
			siz[1]++;bel[i]=1;
		}
		else{
			qp[2].push({b[i]-c[i],i});
			qp[2].push({a[i]-c[i],i});
			siz[2]++;bel[i]=2;
		}
		ans+=max({a[i],b[i],c[i]});
	}
	while(siz[0]>n/2){
		int f=qp[0].top().second;
		int g=qp[0].top().first;
		qp[0].pop();
		if(bel[f]!=0) continue;
		ans+=g;
		siz[0]--;
		bel[f]=3;
	}
	while(siz[1]>n/2){
		int f=qp[1].top().second;
		int g=qp[1].top().first;
		qp[1].pop();
		if(bel[f]!=1) continue;
		ans+=g;
		siz[1]--;
		bel[f]=3;
	}
	while(siz[2]>n/2){
		int f=qp[2].top().second;
		int g=qp[2].top().first;
		qp[2].pop();
		if(bel[f]!=2) continue;
		ans+=g;
		siz[2]--;
		bel[f]=3;
	}
	cout<<ans<<endl;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T;cin>>T;while(T--) solve();
	return 0;
}