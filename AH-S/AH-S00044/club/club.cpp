#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef struct Worker{
	int x,y,z;
	bool use;
}Worker;
Worker a[100010];
int xc,yc,zc;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof a);
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			ans+=max(max(a[i].x,a[i].y),a[i].z);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
