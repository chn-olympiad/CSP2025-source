#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][3];
priority_queue<pair<pair<int,int>,int>>q[3];
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int i=1;i<=n;i++){
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				if(a[i][1]>=a[i][2]) q[0].push({{a[i][1]-a[i][0],1},i});
				else q[0].push({{a[i][2]-a[i][0],2},i});
				if(q[0].size()>n/2){
					q[q[0].top().first.second].push(q[0].top());
					q[0].pop();
				}
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				if(a[i][0]>=a[i][2]) q[1].push({{a[i][0]-a[i][1],0},i});
				else q[1].push({{a[i][2]-a[i][1],2},i});
				if(q[1].size()>n/2){
					q[q[1].top().first.second].push(q[1].top());
					q[1].pop();
				}
			}
			else{
				if(a[i][1]>=a[i][0]) q[2].push({{a[i][1]-a[i][2],1},i});
				else q[2].push({{a[i][0]-a[i][2],0},i});
				if(q[2].size()>n/2){
					q[q[2].top().first.second].push(q[2].top());
					q[2].pop();
				}
			}
		}
		while(!q[0].empty()){
			ans+=a[q[0].top().second][0];
			q[0].pop();
		}
//		cout<<ans<<' ';
		while(!q[1].empty()){
			ans+=a[q[1].top().second][1];
			q[1].pop();
		}
//		cout<<ans<<' ';
		while(!q[2].empty()){
			ans+=a[q[2].top().second][2];
			q[2].pop();
		}
		cout<<ans<<"\n";
	}
}
/*
10
2020 14533 18961 3 2 4428
2423 15344 16322 3 2 978*
1910 6224 16178 3 2 9954
2038 9963 19722 3 2 9759
8375 10557 5444 2 1 5113
3518 14615 17976 3 2 3361
6188 13424 16615 3 2 3191*
8769 509 4394 1 3 4375
958 3195 9953 3 2 6758
16441 5313 10926 1 3 5515

147155
147325

10
6839 5455 15586 3 1
11767 12919 2643 2 1
13775 8904 19938 3 1
13717 11997 15170 3 1
13707 2404 17497 3 1
3471 2462 8073 3 1
18467 14346 18663 3 1
13582 4839 15785 3 1
11875 7476 12308 3 1
8568 3134 18522 3 1

142859
150176
*/
