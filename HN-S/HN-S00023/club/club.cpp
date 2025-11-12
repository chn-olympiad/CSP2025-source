#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	for(cin>>T;T;T--){
		int n,ans=0;
		
		cin>>n;
		priority_queue<int> pq[3];
		for(int i=0;i<n;i++){
			int a[3];
			
			cin>>a[0]>>a[1]>>a[2];
			if(a[0]>=a[1] && a[0]>=a[2]){
				ans+=a[0];
				pq[0].push(max(a[1]-a[0],a[2]-a[0]));
			}else if(a[1]>=a[0] && a[1]>=a[2]){
				ans+=a[1];
				pq[1].push(max(a[0]-a[1],a[2]-a[1]));
			}else{
				ans+=a[2];
				pq[2].push(max(a[0]-a[2],a[1]-a[2]));
			}
		}
		for(int i=0;i<3;i++){
			while(pq[i].size()>n/2){
				ans+=pq[i].top();
				pq[i].pop();
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
