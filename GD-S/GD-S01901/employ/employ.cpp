#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c[505],ans;
char s[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<ans;
	return 0;
}
