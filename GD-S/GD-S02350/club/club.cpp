#include<bits/stdc++.h>
#define int long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=100005;
int T,n,cnt[4];
pair<int,int> a[N][4];
vector<int> g[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=3;i++){
			g[i].clear();
			cnt[i]=0;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].fi,a[i][j].se=j;
			}
			sort(a[i]+1,a[i]+1+3);
			cnt[a[i][3].se]++;
			g[a[i][3].se].push_back(a[i][3].fi-a[i][2].fi);
			ans=ans+a[i][3].fi;
		}
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				sort(g[i].begin(),g[i].end());
				for(int j=0;j<g[i].size()-n/2;j++){
					ans=ans-g[i][j];
				}
			}
		}
		cout<<ans<<"\n";
	}
} 
