#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int t,n,i,j,a[N][4],id[N][4],ans,x,y,z,op,idx,px,py,pz;
bool cmp(int x,int y){
	return a[i][x]>a[i][y];
}
priority_queue<pair<int,int>>q[4];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			for(j=1;j<=3;j++) cin>>a[i][j],id[i][j]=j;
			sort(id[i]+1,id[i]+1+3,cmp);
		}
		ans=0;
		for(i=1;i<=n;i++){
			x=id[i][1],y=id[i][2],z=id[i][3];
			if(q[x].size()==n/2){
				op=q[x].top().first;
				idx=q[x].top().second;
				px=id[idx][1],py=id[idx][2],pz=id[idx][3];
				if(a[i][x]+op<=a[i][y]){
					ans+=a[i][y];
					q[y].push({a[i][z]-a[i][y],i});
				}
				else{
					ans+=a[i][x]+op;
					q[x].pop();q[x].push({a[i][y]-a[i][x],i});
					q[py].push({a[idx][pz]-a[idx][py],idx});
				}
			}
			else{
				ans+=a[i][x];
				q[x].push({a[i][y]-a[i][x],i});
			}
		}
		cout<<ans<<"\n";
		for(i=1;i<=3;i++){
			while(!q[i].empty()) q[i].pop();
		}
	}
	return 0;
}
