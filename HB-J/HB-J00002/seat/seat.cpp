#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll

const int N=105;
int a[N][N];
int n,m,ans,sum=1;

void solve(){
	cin>>n>>m;
	int lr;
	cin>>lr;
	for(int i=1;i<=n*m-1;i++){
		int x;
		cin>>x;
		if(x>lr) ans++;
	}
	while(ans>=n){
		ans-=n;
		sum++;
	}
	if(sum%2==0) cout<<sum<<" "<<n-ans;
	else cout<<sum<<" "<<ans+1;
	return;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	t=1;
	while(t--)
		solve();
	return 0;
}
