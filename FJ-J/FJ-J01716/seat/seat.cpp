#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	int flc=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	if(flc==a[i]){
		int ans1=(i-1)/n+1;
		cout<<ans1<<' ';
		i%=n;
		if(i==0)i=n;
		if(ans1&1)
		cout<<i;
		else cout<<n-i+1;
		return;
	}
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}

// Nephren Ruq
