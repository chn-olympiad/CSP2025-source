#include <bits/stdc++.h>
using namespace std;
const int N=1e5+55;
int n,a[N][5],tp;
pair<int,int> tmp[N<<1];
bool vis[N];
vector<int> b[5];

void solve(){
	cin>>n; tp=0;
	for(int i=1;i<=3;++i) b[i].clear();
	memset(vis,0,sizeof(bool)*(n+5));
	for(int i=1;i<=n;++i){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		int t=max({a[i][1],a[i][2],a[i][3]});
		ans+=t;
		for(int j=1;j<=3;++j){
			if(t==a[i][j]) {
				b[j].push_back(i); 
				break; 
			}
		}
	}
	int tn=(n>>1),mxc=0,mxi=0;
	for(int i=1;i<=3;++i){
		if((int)b[i].size()>mxc){
			mxc=b[i].size();
			mxi=i;
		}
	}
	if(mxc<=tn){
		cout<<ans<<"\n";
		return;
	}
	for(int t:b[mxi]){
		for(int j=1;j<=3;++j){
			if(j==mxi) continue;
			tmp[++tp]={a[t][mxi]-a[t][j],t};
		}
	}
	sort(tmp+1,tmp+tp+1);
	for(int i=1;i<=tp&&mxc>tn;++i){
		if(vis[tmp[i].second]) continue;
		vis[tmp[i].second]=1;
		ans-=tmp[i].first;
		mxc-=1;
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club5.in","r",stdin);
//	freopen("club5.result","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin>>T;
	while(T--) solve();
	return 0;
}
