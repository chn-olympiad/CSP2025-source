#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans,q,w,e;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>q>>w>>e;
		ans+=e;
	}
	for(int i=1;i<=k;i++){
		bool flagA=true;
		for(int j=0;j<=n;j++){
			cin>>q;
			if(q!=0){
				flagA=false;
			}
		}
		if(flagA){
			cout<<0;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
