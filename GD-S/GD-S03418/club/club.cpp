#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,a[N][3],ans;
priority_queue<int,vector<int>,greater<int>> pq[3]; //反悔代价堆 取最小反悔代价 
//在同一道题目中只有一个堆会爆 

void solve(){
	ans = 0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	for(int i=1;i<=n;i++){
		if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2]){
			ans+=a[i][0];
			pq[0].push(min(a[i][0]-a[i][1],a[i][0]-a[i][2]));
		}
		else if(a[i][1]>=a[i][0] && a[i][1]>=a[i][2]){
			ans+=a[i][1];
			pq[1].push(min(a[i][1]-a[i][0],a[i][1]-a[i][2]));
		}
		else{
			ans+=a[i][2];
			pq[2].push(min(a[i][2]-a[i][0],a[i][2]-a[i][1]));
		}
		for(int j=0;j<3;j++){
			if(pq[j].size()>(n/2)){
				int tmp = pq[j].top();
				pq[j].pop();
				ans-=tmp;
			}
		}
	}
	cout<<ans<<"\n";
	for(int j=0;j<3;j++)
		while(!pq[j].empty()) pq[j].pop();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
} 
