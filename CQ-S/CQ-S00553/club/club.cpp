#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t;
ll n,ans;
ll a[100005][5];
priority_queue<ll>p,q,r;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++) cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
		if(a[i][1]>a[i][2]){
			if(a[i][1]>a[i][3]) ans+=a[i][1],p.push(max(a[i][2],a[i][3])-a[i][1]);
			else ans+=a[i][3],r.push(max(a[i][1],a[i][2])-a[i][3]);
		}
		else{
			if(a[i][2]>a[i][3]) ans+=a[i][2],q.push(max(a[i][1],a[i][3])-a[i][2]);
			else ans+=a[i][3],r.push(max(a[i][1],a[i][2])-a[i][3]);
		}
	}
	while(p.size()>n/2) ans+=p.top(),p.pop();
	while(q.size()>n/2) ans+=q.top(),q.pop();
	while(r.size()>n/2) ans+=r.top(),r.pop();
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
	cin>>t;
	while(t--){
		solve();
		ans=0;
		while(!p.empty()) p.pop();
		while(!q.empty()) q.pop();
		while(!r.empty()) r.pop();
	}
	return 0;
}
