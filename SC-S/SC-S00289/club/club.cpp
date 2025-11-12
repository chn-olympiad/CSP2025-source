#include<bits/stdc++.h>
using namespace std;
#define int long long
struct p{
	int x[4],c;
} a[100005];
bool cmp(p n,p m){
	return n.x[1]<n.x[2];
}
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3];
	}
	sort(a+1,a+n+1,cmp);
	int cnt=0;
	for(int i=n/2+1;i<=n;i++){
		cnt+=a[i].x[1];
	}
	cout<<cnt<<"\n"; 
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}
