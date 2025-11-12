#include<bits/stdc++.h>
#define endl '\n'
#define debug(x) cerr<<#x<<':'<<x<<endl
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=1e5+5;
int T;
int n;
int a[N][4];
int mx[N],md[N];
int cnt[4];
void solve(){
	cin>>n;
	int ans=0;
	for(int i=1;i<=3;i++) cnt[i]=0;
	priority_queue<int> q[4];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++) cin>>a[i][j];
		int Mx=max(a[i][1],max(a[i][2],a[i][3]));
		if(a[i][1]==Mx) mx[i]=1;
		else if(a[i][2]==Mx) mx[i]=2;
		else mx[i]=3;
		ans+=a[i][mx[i]];
		sort(a[i]+1,a[i]+4);
		md[i]=a[i][2];
		cnt[mx[i]]++;
		q[mx[i]].push(md[i]-Mx);
	}
	int tot=max(cnt[1],max(cnt[2],cnt[3]));
	int pos=0;
	if(cnt[1]==tot) pos=1;
	if(cnt[2]==tot) pos=2;
	if(cnt[3]==tot) pos=3;
//	debug(tot);
	while(tot>n/2){
		ans+=q[pos].top();
		q[pos].pop();
		tot--;
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	IOS;
	cin>>T;
	while(T--) solve();
	return 0;
}
/*
5491 4476 6362 3
9805 9130 15480 3
9090 9901 10480 3
6326 6516 1985 2
9119 2924 6420 1
9826 12689 7592 2
7293 16544 12901 2
11905 18183 18712 3
9015 3463 13025 3
1792 2433 17042 3
*/
