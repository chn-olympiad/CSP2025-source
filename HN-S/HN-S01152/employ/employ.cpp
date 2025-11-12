#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=2e6+10;
const ll mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m; cin>>n>>m;
	ll sum=1;
	for(int i=m;i>=1;i--){
		sum=(sum*i)%mod;
	}
	cout<<sum;
	return 0;
}

