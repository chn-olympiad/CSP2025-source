#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
//const int N =
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,a,x,cnt=1;
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n*m;i++){
		cin>>x;
		if(x>a) cnt++;
	}
	int c=(cnt+n-1)/n,r=(cnt%n?cnt%n:n);
	cout<<c<<" "<<(c%2?r:n-r+1);
	return 0;
}
