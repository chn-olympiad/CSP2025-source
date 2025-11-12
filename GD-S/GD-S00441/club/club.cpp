#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n;
struct node{
	int x, y, z;
}a[N];
bool cmp(node x,node y){
	return max({x.x,x.y,x.z})>max({y.x,y.y,y.z});
}
void solve(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	sort(a+1,a+n+1,cmp);
	int c1=0, c2=0, c3=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		int cnt=0;
		if(c1<2*n && a[i].x>cnt){
			cnt=a[i].x;
		}
		if(c2<2*n && a[i].y>cnt){
			cnt=a[i].y;
		}
		if(c3<2*n && a[i].z>cnt){
			cnt=a[i].z;
		}
		if(cnt==a[i].x){
			c1++;
		}else if(cnt==a[i].y){
			c2++;
		}else{
			c3++;
		}
		ans+=cnt;
	}
	int ans2=0;
	for(int i=n;i>=1;i--){
		int cnt=0;
		if(c1<2*n && a[i].x>cnt){
			cnt=a[i].x;
		}
		if(c2<2*n && a[i].y>cnt){
			cnt=a[i].y;
		}
		if(c3<2*n && a[i].z>cnt){
			cnt=a[i].z;
		}
		if(cnt==a[i].x){
			c1++;
		}else if(cnt==a[i].y){
			c2++;
		}else{
			c3++;
		}
		ans2+=cnt;
	}
	cout << max(ans,ans2) << "\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
} 
