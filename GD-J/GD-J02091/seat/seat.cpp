#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=105;
ll a[N];
void solve(){
	ll n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	if(n*m==1){
		cout << "1 1\n";
		return ;
	}
	ll cnt=1;
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]) cnt++;
	}
	ll tmp=cnt/n;
	if(cnt%n==0){
		if(tmp%2==0){
			cout << tmp << " " << 1 << "\n"; 
		}
		else cout << tmp << " " << m << "\n";
	}
	else{
		if(tmp%2==0){
			cout << tmp+1 << " " << cnt-tmp*n << "\n";
		}
		else{
			cout << tmp+1 << " " << m-(cnt-tmp*n)+1 << "\n";
		}
	}
	return ;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
 */
