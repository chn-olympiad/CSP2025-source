#include<bits/stdc++.h>
#define int long long
using namespace std;
long long a[100005],b[100005],c[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n,tf=0,ts=0,tt=0,ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			int x,y,z;
			cin >> x >> y >> z;
			if(x >= y and x >= z){
				tf++;
				if(y >= z){
					a[tf] = x-y;
				}
				else{
					a[tf]=x-z;
				}
			}
			if(y > x and y >= z){
				ts++;
				if(x >= z){
					b[ts] = y-x;
				}
				else {
					b[ts]= y-z;
				}
			}
			if(z > y and z > x){
				tt++;
				if(x >= y){
					c[tt] = z-x;
				}
				else {
					c[tt]=z-y;
				}
			}
			ans += max(x,max(y,z));
		}
		if(tf <= n/2 and ts <= n/2 and tt <= n/2){
			cout << ans << endl;
		}
		else{
			if(tf > n/2){
				sort(a+1,a+tf+1);
				for(int i = tf;i > n/2;i--)ans -= a[tf+1-i];
			}
			if(ts > n/2){
				sort(a+1,a+ts+1);
				for(int i = ts;i > n/2;i--)ans -= b[ts+1-i];
			}
			if(tt > n/2){
				sort(a+1,a+tt+1);
				for(int i = tt;i > n/2;i--)ans -= c[tt+1-i];
			}
			cout << ans << endl;
		}
	}
	return 0;
}
