#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[110000][3];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;cin>>T;
	while(T--){
		int n,ans=0;cin>>n;
		priority_queue<int> q[3];
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1] and a[i][0]>=a[i][2]){
				ans+=a[i][0];
				q[0].push(max(a[i][1],a[i][2])-a[i][0]);
			}else if(a[i][1]>=a[i][0] and a[i][1]>=a[i][2]){
				ans+=a[i][1];
				q[1].push(max(a[i][0],a[i][2])-a[i][1]);
			}else if(a[i][2]>=a[i][0] and a[i][2]>=a[i][1]){
				ans+=a[i][2];
				q[2].push(max(a[i][1],a[i][0])-a[i][2]);
			}
		}
		for(int i=0;i<=2;i++) while((int)q[i].size()>n/2) ans+=q[i].top(),q[i].pop();
		cout<<ans<<'\n';
	}
	return 0;
}
//Wo shi chang zhui yi guo qu...
//Wo gai zai na li ting liu ,wo wen wo zi ji.