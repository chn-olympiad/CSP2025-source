#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int T,n,a[N][4],b[4],ans;
priority_queue<int> q[4];
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		b[1]=b[2]=b[3]=ans=0;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				++b[1];ans+=a[i][1];
				q[1].push(max(a[i][2],a[i][3])-a[i][1]);
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				++b[2];ans+=a[i][2];
				q[2].push(max(a[i][1],a[i][3])-a[i][2]);
			}
			else{
				++b[3];ans+=a[i][3];
				q[3].push(max(a[i][1],a[i][2])-a[i][3]);
			}
		}
		for(int g=1;g<=3;g++){
			if(b[g]>n/2){
				for(int i=1;i<=b[g]-n/2;i++){
					ans+=q[g].top();
					q[g].pop();
				}
			}
			while(!q[g].empty()) q[g].pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}

