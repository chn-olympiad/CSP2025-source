#include<bits/stdc++.h>
#define int long long
#define For(i,x,y) for(int i = x;i <= y;i ++ )
#define For_(i,x,y) for(int i = x;i >= y;i --)
#define fs first
#define sc second
#define y0 y0_
#define y1 y1_
#define yn yn_
#define j0 j0_
#define j1 j1_
#define jn jn_
#define pii pair<int,int> 
#define pb push_back
using namespace std;
const int N = 2e5 + 5;
const int mod = 998244353;
int n;
int a[N][5];
int cnt[5];
void solve(){
	cin >> n;
	For(i,1,3) cnt[i] = 0;
	For(i,1,n) cin >> a[i][1] >> a[i][2] >> a[i][3];
	int ans = 0;
	For(i,1,n){
		if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) cnt[1] ++,ans += a[i][1];
		else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) cnt[2] ++,ans += a[i][2];
		else cnt[3] ++,ans += a[i][3];
	}
	if(cnt[1] <= n/2 && cnt[2] <= n/2 && cnt[3] <= n/2){
		cout << ans << endl;return ;
	}
	
//	cout <<cnt[1] << " " << cnt[2] << " "<<cnt[3] << endl;
	
	if(cnt[1] > n/2){
		vector<int> v;
		For(i,1,n) if(min(a[i][1] - a[i][2],a[i][1] - a[i][3]) >= 0)v.pb(min(a[i][1] - a[i][2],a[i][1] - a[i][3]));
		sort(v.begin(),v.end());
		For(i,0,cnt[1]-n/2-1) ans -= v[i];
	}else if(cnt[2] > n/2){
		vector<int> v;
		For(i,1,n) if(min(a[i][2] - a[i][1],a[i][2] - a[i][3]) >= 0)v.pb(min(a[i][2] - a[i][1],a[i][2] - a[i][3]));
		sort(v.begin(),v.end());
		For(i,0,cnt[2]-n/2-1) ans -= v[i];
	}else if(cnt[3] > n/2){
		vector<int> v;
		For(i,1,n) if(min(a[i][3] - a[i][2],a[i][3] - a[i][1]) >= 0)v.pb(min(a[i][3] - a[i][2],a[i][3] - a[i][1]));
		sort(v.begin(),v.end());
		For(i,0,cnt[3]-n/2-1) {
			ans -= v[i];
//			cout << v[i] << " ";
		}
//		cout<<endl;
	}
	
	cout << ans << endl;
} signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	cin >> T;
	while(T--){
		solve();
	}return 0;
}

/*
1 
10 
2020 14533 18961 
2423 15344 16322 
1910 6224 16178 
2038 9963 19722  
8375 10557 5444 
3518 14615 17976 
6188 13424 16615 
8769 509 4394 
958 3195 9953 
16441 5313 10926

147325 

*/

