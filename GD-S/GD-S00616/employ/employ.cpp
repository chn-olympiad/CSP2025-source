#include<iostream>
#include<cstring>
using namespace std;
#define int long long
int n,m;
long long ans = 1;
string s;
int c,cnt;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i<=n;i++){
		cin>>c;
		if(c == 0)cnt++;
	}
	n -= cnt;
	for(int i = n-m+1;i<=n;i++){
		ans *= i;
		ans %= 998244353;
	}
	cout<<ans%998244353;
	return 0;
}
