#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=600;
const int mod=998244353;
int n,m;
string s;
int c[N];
int sum=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		sum*=i%mod;
	}
	cout<<sum;
	return 0;
}
