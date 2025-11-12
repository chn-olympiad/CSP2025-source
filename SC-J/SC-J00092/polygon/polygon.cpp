#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int mod=998244353;
long long n,m,a[5005],ans;
void dfs(int now,int sum,int mx){
	if(now>n) return;
	if(sum>(mx<<1) and now>=3) ans=(ans+1)%mod;
	int bef=mx;
	for(int i=now+1;i<=n;i++){
		sum+=a[i],mx=a[i];
		dfs(i,sum,mx);
		sum-=a[i],mx=bef;
	}
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<3){
		cout<<"0";
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<ans;
	return 0;
}

/*
5
1 2 3 4 5

5
2 2 3 8 10

20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/