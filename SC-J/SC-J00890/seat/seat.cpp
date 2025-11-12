#include<bits/stdc++.h>
#define int long long
using namespace std;

int x[105];

bool cnt(int la1,int la2){
	return la1 > la2;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>x[i];
	int ming = x[1];
	int seat_m = 0;
	sort(x+1,x+1+n*m,cnt);
	for(int i=1;i<=n*m;i++){
		if(x[i]==ming) seat_m = i; 
	}
	if(seat_m%(2*n) > n) cout<<seat_m/n+1<<' '<<n-seat_m%n+1;
	else if(seat_m%(2*n) == 0) cout<<seat_m/n<<' '<<1;
	else if(seat_m%(2*n) == n) cout<<seat_m/n<<' '<<n;
	else cout<<seat_m/n+1<<' '<<seat_m%(2*n);
	return 0;
}