#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef pair<int,int>pii;
typedef vector<int>vint;
const int N=100010;
int T,n;
pii a[N][3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		vint c(3);
		vector<vint>del(3);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j].fi;
				a[i][j].se=j;
			}
			sort(a[i],a[i]+3);
			ans+=a[i][2].fi;
			c[a[i][2].se]++;
			del[a[i][2].se].pb(a[i][2].fi-a[i][1].fi);
		}
		for(int i=0;i<3;i++)
			if(c[i]>n/2){
				sort(del[i].begin(),del[i].end());
				for(int j=0;j<c[i]-n/2;j++){
					ans-=del[i][j];
				}
			}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
Ren5Jie4Di4Ling5%
*/