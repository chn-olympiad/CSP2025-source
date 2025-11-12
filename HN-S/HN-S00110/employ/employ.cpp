#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N = 1e6 + 6;
string s;
int c[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	int ans=0;
	ans=c[n];
	cout<<ans%998244353<<endl;
	return 0;
}
