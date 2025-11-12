#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m;
string s;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int x;
	for(int i=1;i<=n;i++) cin>>x;
	int rp=1;
	for(int i=1;i<=n;i++) rp=rp*i%mod;
	cout<<rp%mod;
	return 0;
}
