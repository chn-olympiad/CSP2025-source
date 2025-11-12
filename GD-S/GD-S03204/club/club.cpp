#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n,ans=0,a[4],cnt[]={0,0,0,0};
	priority_queue<int,vector<int>,greater<int>> q[4];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[1]>>a[2]>>a[3];
		int p=max_element(a+1,a+4)-a;
		cnt[p]++;
		sort(a+1,a+4);
		if(cnt[p]>n/2){
			if(a[3]-a[2]>q[p].top()){
				ans-=q[p].top();
				q[p].pop();
				ans+=a[3];
				q[p].push(a[3]-a[2]);
			}
			else ans+=a[2];
		}
		else{
			ans+=a[3];
			q[p].push(a[3]-a[2]);
		}
	}
	cout<<ans<<'\n';
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
