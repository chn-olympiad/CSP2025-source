#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=1e5+10;
int T,n,a[N][4],nxt[N];

bool cmp(int x,int y){
	return nxt[x]<nxt[y];
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int mx=0,nmx=0;
		for(int j:{1,2,3}) cin>>a[i][j];
		for(int j:{1,2,3})
			if(a[i][j]>mx) nmx=mx,mx=a[i][j];
			else if(a[i][j]>nmx) nmx=a[i][j];
		nxt[i]=mx-nmx;	
	}
	int ans=0;
	vector<int> g[4];
	for(int i=1;i<=n;i++){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			ans+=a[i][1],g[1].push_back(i); continue;
		}
		if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			ans+=a[i][2],g[2].push_back(i); continue;
		}
		if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
			ans+=a[i][3],g[3].push_back(i); continue;
		}
	}
	if(g[1].size()>n/2){
		sort(g[1].begin(),g[1].end(),cmp);
		int delta=g[1].size()-n/2;
		for(int i=0;i<delta;i++) ans-=nxt[g[1][i]];
	}
	if(g[2].size()>n/2){
		sort(g[2].begin(),g[2].end(),cmp);
		int delta=g[2].size()-n/2;
		for(int i=0;i<delta;i++) ans-=nxt[g[2][i]];
	}
	if(g[3].size()>n/2){
		sort(g[3].begin(),g[3].end(),cmp);
		int delta=g[3].size()-n/2;
		for(int i=0;i<delta;i++) ans-=nxt[g[3][i]];
	}
	cout<<ans<<endl;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}