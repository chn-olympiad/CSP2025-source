#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
int t;
int n;
int a[100005][5];
int ans;
int rem(int x){
	int ma=max(a[x][1],max(a[x][2],a[x][3]));
	if(ma==a[x][1])return 1;
	if(ma==a[x][2])return 2;
	return 3;
}
int ren(int x){
	if(a[x][1]>=a[x][2]&&a[x][2]>=a[x][3])return 2;
	if(a[x][3]>=a[x][2]&&a[x][2]>=a[x][1])return 2;
	if(a[x][2]>=a[x][1]&&a[x][1]>=a[x][3])return 1;
	if(a[x][3]>=a[x][1]&&a[x][1]>=a[x][2])return 1;
	if(a[x][1]>=a[x][3]&&a[x][3]>=a[x][2])return 3;
	if(a[x][2]>=a[x][3]&&a[x][3]>=a[x][1])return 3;
}
priority_queue<pii,vector<pii>,greater<pii> >q[3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3]; 
		}
				
		for(int i=1;i<=n;i++){
			int x=rem(i);
			int y=ren(i);
			int v=a[i][x]-a[i][y];
			if(q[x].size()<n/2){
				q[x].push({v,i});
			}else{
				if(q[x].top().first>=v){
					q[y].push({v,i});
				}else{
					q[y].push(q[x].top());
					q[x].pop();
					q[x].push({v,i});
				}
			}
		} 
		int ans=0;
		for(int i=1;i<=3;i++){
			while(q[i].size()){
				ans+=a[q[i].top().second][i];
				q[i].pop();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/






