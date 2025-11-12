#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int n,m,f,ans=1;
void solve(){
	cin>>n>>m;
	cin>>f;
	for(int i=2,x;i<=n*m;i++){
		cin>>x;
		if(x>f)ans++;
	}
	int c=ans/m,r=ans%m;
	if(r==0){
		if(c%2)cout<<c<<" "<<n;
		else cout<<c<<" "<<1;
		return ;
	}
	c++;
	if(c%2)cout<<c<<" "<<r;
	else cout<<c<<" "<<n-r+1;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num=1;
	//cin>>num;
	while(num--)solve();
	return 0;
}
