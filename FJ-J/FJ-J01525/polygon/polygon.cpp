#include<bits/stdc++.h>
using namespace std;
int a[5005],n;
long long ans;
int b[5005];
void solve(int sum,int maxn,int step,int cnt) {
	if(sum>maxn*2&&cnt>=3) {
		ans++;
	}
	if(step>=n)return;
	for(int i=step; i<n; i++) {
		solve(sum+a[i],max(maxn,a[i]),i+1,cnt+1);
	}
	return;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	solve(0,0,0,0);
	cout<<ans%998244353;

	return 0;
}
