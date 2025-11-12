#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t,n,a[100005][3];
vector<int> v[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		v[0].clear(),v[1].clear(),v[2].clear();
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			array<int,2> mx={0,0},smx={0,0};
			for(int j=0;j<3;j++){
				array<int,2> nw={a[i][j],j};
				if(nw>mx) smx=mx,mx=nw;
				else if(nw>smx) smx=nw;
			}
			ans+=mx[0],v[mx[1]].push_back(mx[0]-smx[0]);
		}
		if(v[0].size()*2<=n&&v[1].size()*2<=n&&v[2].size()*2<=n) cout<<ans<<'\n';
		else{
			int nw=0;
			if(v[1].size()*2>n) nw=1;
			if(v[2].size()*2>n) nw=2;
			sort(v[nw].begin(),v[nw].end());
			int num=v[nw].size()-n/2;
			for(int i=0;i<num;i++) ans-=v[nw][i];
			cout<<ans<<'\n';
		}
	}
	return 0;
}
