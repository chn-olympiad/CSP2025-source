#include<bits/stdc++.h>
using namespace std;
const int N = 505,mod = 998244353;
typedef long long LL;

int n,m;
string s;
int c[N];
LL sum = 1;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		sum = 1ll*(sum%mod)*i%mod;
	}
	cout<<sum;
	return 0;
}
//Shawty its so freaking heartache
