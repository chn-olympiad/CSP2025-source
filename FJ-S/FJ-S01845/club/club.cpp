#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;

int n;
int a[N][3];
priority_queue<pair<pair<int,int>,int>>q[3];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)for(int j=0;j<3;j++)cin>>a[i][j];
		for(int i=1;i<=n;i++){
			int mx=0,fmx=0;
			for(int j=1;j<3;j++)if(a[i][j]>a[i][mx])mx=j;
			if(mx==0){if(a[i][1]>a[i][2])fmx=1;else fmx=2;}
			if(mx==1){if(a[i][0]>a[i][2])fmx=0;else fmx=2;}
			if(mx==2){if(a[i][0]>a[i][1])fmx=0;else fmx=1;}
			if((int)q[mx].size()<(n/2)){q[mx].push({{a[i][fmx]-a[i][mx],fmx},i});}
			else{
				int id=q[mx].top().first.second,val=q[mx].top().first.first,idd=q[mx].top().second;
				if(val+a[i][mx]-a[i][fmx]>0)q[mx].pop(),q[mx].push({{a[i][fmx]-a[i][mx],fmx},i}),q[id].push({{0,0},idd});
				else q[fmx].push({{0,0},i});
			}
		}
		int ans=0;
		while(!q[0].empty())ans+=a[q[0].top().second][0],q[0].pop();
		while(!q[1].empty())ans+=a[q[1].top().second][1],q[1].pop();
		while(!q[2].empty())ans+=a[q[2].top().second][2],q[2].pop();
		cout<<ans<<'\n';
	}
	return 0;
}
