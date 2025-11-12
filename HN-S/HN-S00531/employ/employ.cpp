#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500+5;
const int mod = 998244353;
int n,m;
string s;
int a[N],b[N];
int vis[N];
int ans;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 0;i < n;i++) b[i+1] = s[i] - '0';
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
		if(vis[i] == 0) vis[i] = vis[i-1]++;
	}
	
	sort(a+1,a+n+1);
	
	for(int i = 1;i <= n;i++){
		if(vis[i] < a[i]) ans++;
	}
	
	cout<<ans;
	return 0;
}

