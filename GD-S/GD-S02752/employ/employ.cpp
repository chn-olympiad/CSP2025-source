#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,m;
string s;
int c[1005];
int ans;
bool vis[1005];
int a[1005];
void dfs(int pos,int cnt,int sum) {
	if(pos==n+1 && sum>=m) {
		ans++;
		ans%=mod;
		return ;
	}
	if(m-sum>n-pos+1) {
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(vis[i]) {
			continue;
		}
		vis[i]=true;
		if(cnt>=c[i] || s[pos-1]=='0') {
			dfs(pos+1,cnt+1,sum);
		}
		else {
			dfs(pos+1,cnt,sum+1);
		}
		vis[i]=false;
	}
	return ;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++) {
		if(s[i]=='1') {
			cnt++;
		}
	}
	if(cnt<m) {
		cout<<0;
		return 0;
	}
	if(m==n) {
		for(int i=0;i<s.size();i++) {
			if(s[i]=='0' || c[i+1]==0) {
				cout<<0;
				return 0;
			}
		}
		int sum=1;
		for(int i=2;i<=n;i++) {
			sum*=i;
			sum%=mod;
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++) {
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
