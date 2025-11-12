#include<bits/stdc++.h>
#define md 998244353
#define ll long long
using namespace std;
int n;
int a[5005];
int ans=0;
void dfs(int now,string s) {
	if(now>n) {
		int mx=0,sum=0;
		for(int i=0; i<s.size(); i++) {
			if(s[i]=='1') {
				mx=max(mx,a[i+1]);
				sum+=a[i+1];
			}
		}
		if(sum>2*mx) {
			ans++;
			ans%=md;
		}
		return;
	}
	dfs(now+1,s+'0');
	dfs(now+1,s+'1');
}
int mx=-1;
int C(int x,int y){
	ll res=1;
	for(int i=x;i>=max(x-y+1,y+1);i--){
		res*=i;
		res/=(x-i+1);
	}
	return res%md;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i],mx=max(mx,a[i]);
	if(mx==1){
		int ans=0;
		for(int i=3;i<=n;i++){
			 ans+=C(n,i);
			 ans%=md;
		}
		cout<<ans;
		return 0;
	}
	if(n<=2) {
		cout<<0;
		return 0;
	}
	if(n==3) {
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) cout<<1;
		else cout<<0;
		return 0;
	}
	else {
		dfs(1,"");
		cout<<ans%md;
	}
	return 0;
}
/*
5
1 2 3 4 5
*/
