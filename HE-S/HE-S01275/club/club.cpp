#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e5 + 10;
struct node{
	int Max,Mi,max,mi;
}a[N];
int T;
int ans;
int n,club[4];
priority_queue<pair<int,int> >q1,q2,q3;
inline void solve(){
	cin >> n;
	int k = n / 2;
	int ans = 0;
	while(!q1.empty())q1.pop();
	while(!q2.empty())q2.pop();
	while(!q3.empty())q3.pop();
	for(int i = 1;i <= 3;i ++)club[i] = 0;
	for(int i = 1;i <= n;i ++){
		int q1,q2,q3;
		cin >> q1 >> q2 >> q3;
		int ma = max({q1,q2,q3});
		if(ma == q1)a[i].Max = q1,a[i].Mi = 1,q1 = -1;
		if(ma == q2)a[i].Max = q2,a[i].Mi = 2,q2 = -1;
		if(ma == q3)a[i].Max = q3,a[i].Mi = 3,q3 = -1;
		ma = max({q1,q2,q3});
		if(ma == q1)a[i].max = q1,a[i].mi = 1;
		if(ma == q2)a[i].max = q2,a[i].mi = 2;
		if(ma == q3)a[i].max = q3,a[i].mi = 3;
	}
	for(int i = 1;i <= n;i ++){
		if(club[a[i].Mi] == k){
			if(a[i].Mi == 1){
				if((a[i].Max - a[i].max) > - q1.top().first){
					club[q1.top().second] ++;
					ans = ans + q1.top().first + a[i].Max;
					q1.pop();
					q1.push({-(a[i].Max - a[i].max),a[i].mi});
				}else{
				ans += a[i].max;
					club[a[i].mi] ++;
				}
			}
			if(a[i].Mi == 2){
				if((a[i].Max - a[i].max) > - q2.top().first){
					club[q2.top().second] ++;
					ans = ans + q2.top().first + a[i].Max;
					q2.pop();
					q2.push({-(a[i].Max - a[i].max),a[i].mi});
				}else{
					ans += a[i].max;
					club[a[i].mi] ++;
				}
			}
			if(a[i].Mi == 3){
				if((a[i].Max - a[i].max) > - q3.top().first){
		club[q3.top().second] ++;
		ans = ans + q3.top().first + a[i].Max;
		q3.pop();
		q3.push({-(a[i].Max - a[i].max),a[i].mi});
	}else{
		ans += a[i].max;
		club[a[i].mi] ++;
	}
			}
		}else{
			club[a[i].Mi] ++;
			ans += a[i].Max;
			if(a[i].Mi == 1)q1.push({-(a[i].Max - a[i].max),a[i].mi});
			if(a[i].Mi == 2)q2.push({-(a[i].Max - a[i].max),a[i].mi});
			if(a[i].Mi == 3)q3.push({-(a[i].Max - a[i].max),a[i].mi});
		}
	}
	cout << ans << endl;
	
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> T;
	while(T --){
		solve();
	}
	return 0;
} 
