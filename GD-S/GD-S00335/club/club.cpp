#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n;
ll a[100005][4],b[100005];
bool cmp(ll x,ll y){
	return x > y;
}
ll slv(ll c){
	ll ans = 0;
	for(int i=1;i<=n;i++){
		ans += a[i][c];
		b[i] = -1e10;
		for(int k=1;k<=3;k++){
			if(k == c) continue;
			b[i] = max(b[i] , a[i][k] - a[i][c]);
		}
	}
	sort(b+1,b+n+1,cmp);
	ll cnt = 0;
	while(b[cnt+1] > 0 && cnt + 1 <= n) cnt++;
	if(cnt > n / 2) return -1;
	for(int i=1;i<=n/2;i++) ans += b[i];
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ll ans = -1;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=3;i++){
			ans = max(ans,slv(i));
		}
		if(ans == -1){
			ans = 0;
			for(int i=1;i<=n;i++) ans += max(a[i][1] , max(a[i][2] , a[i][3]));
		}
		cout<<ans<<endl;
	}
	return 0;
} 
/*
15:05
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13

1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
