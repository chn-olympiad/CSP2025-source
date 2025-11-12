#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[505], b[505], d[505], s[505], ans=0, p=998244353;
char c[505];
void dfs(int now) {
	if(now==n+1) {
		int cnt=0, sum=0;
		for(int i=1; i<=n; i++) {
			if(c[i]=='0') {
				cnt++;
				continue;
			}
			if(a[d[i]]<=cnt) cnt++;
			else sum++;
		}
		if(sum>=m) ans++;
		return ;
	}
	for(int i=1; i<=n; i++) {
		if(b[i]) continue;
		b[i]=now;
		d[now]=i;
		dfs(now+1);
		b[i]=0;
	}
} 
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>c[i];
	for(int i=1; i<=n; i++) cin>>a[i];
	if(n<=10) {
		dfs(1);
		cout<<ans;
	}
	else if(m==1) {
		int anss=1;
		ans=1;
		for(int i=2; i<=n; i++) ans=(ans*i)%p;
		for(int i=1; i<=n; i++) s[a[i]]++;
		for(int i=1; i<=n; i++) s[i]=s[i-1]+s[i];
		int cnt=0;
		for(int i=1; i<=n; i++) {
			if(c[i]=='0') continue;
			anss=(anss*(s[i-1]-cnt))%p;
			cnt++;
		}
		cnt=n-cnt;
		for(int i=2; i<=cnt; i++) anss=(anss*i)%p;
		cout<<(ans-anss+p+p)%p;
	}
	else if(m==n) {
		int f=0;
		for(int i=1; i<=n; i++) {
			if(c[i]=='0') {
				f=1;
				break;
			}
		}
		if(f) {
			cout<<"0";
			return 0;
		}
		else {
			ans=1;
			for(int i=2; i<=n; i++) ans=(ans*i)%p;
			cout<<ans;
		}
	}
	return 0;
} 
