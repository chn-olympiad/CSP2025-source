#include<bits/stdc++.h>

using namespace std;
bool Mbe;

constexpr int maxn=1e5+10;

int n,a[maxn][3];

priority_queue<int> q[3];

void clean(){
	for(int i:{0,1,2}) while(!q[i].empty()) q[i].pop();
}

void solve(){
	clean();
	
	cin>>n;
	for(int i=1;i<=n;++i) for(int j:{0,1,2}) cin>>a[i][j];
	
	int ans=0;
	for(int i=1;i<=n;++i){
		int mx=max({a[i][0],a[i][1],a[i][2]});
		ans+=mx;
		if(mx==a[i][0]) q[0].push(max(a[i][1],a[i][2])-a[i][0]);
		else if(mx==a[i][1]) q[1].push(max(a[i][0],a[i][2])-a[i][1]);
		else q[2].push(max(a[i][0],a[i][1])-a[i][2]);
	}
	
	if((int)q[0].size()<=(n/2)&&(int)q[1].size()<=(n/2)&&(int)q[2].size()<=(n/2)){
		cout<<ans<<'\n';
	}
	else{
		int p=0;
		for(int i:{0,1,2}) if((int)q[i].size()>(n/2)){
			p=i;break;
		}
		while((int)q[p].size()>(n/2)){
			ans+=q[p].top();q[p].pop();
		}
		cout<<ans<<'\n';
	}
}

bool Med;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	
//	freopen("club5.in","r",stdin);
//	freopen("clubmy.out","w",stdout);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int _;cin>>_;while(_--) solve();
	
	cerr<<'\n'<<fabs(&Med-&Mbe)/1048576.0<<"MB\n";
	cerr<<'\n'<<1e3*clock()/CLOCKS_PER_SEC<<"ms\n";	
	return 0;
}