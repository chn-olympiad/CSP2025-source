#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e3+10;
int n,m,a[maxn];
void solve1(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int t=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*m+j]==t){
				cout<<i<<" ";
				if(i%2)cout<<j;
				else cout<<n-j+1;
				return;
			}
		}
	}
}
void solve(){
	if(1)solve1();
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
