#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=505;
const int MOD=998244353;
int n,m;
int s[N],c[N];
int a[N];
bool is[N];
ll sum[N];
ll cnt;
void dfs(int now) {
//	cout<<"f("<<now<<")->";
	if(now==n+1) {
//		cout<<endl<<"now:"<<endl;
//		for(int i=1; i<=n; i++) {
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
		ll ans=0;
		for(int i=1; i<=n; i++) {
			int pos=a[i];
			if(sum[i-1]>=c[pos]||s[pos]==0) {
				sum[i]=sum[i-1]+1;
				ans++;
			}
		}
		if(n-ans>=m) {
			cnt++;
//			cout<<"succeed"<<endl;
		}
		if(cnt>=MOD)cnt-=MOD;
		return;
	}
	for(int i=1; i<=n; i++) {
		if(!is[i]) {
			a[now]=i;
			is[i]=true;
			dfs(now+1);
			is[i]=false;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	string t;
	cin>>t;
	for(int i=0; i<t.size(); i++) {
		s[i+1]=t[i]-48;
	}
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	dfs(1);
	cout<<cnt;
	return 0;
}
