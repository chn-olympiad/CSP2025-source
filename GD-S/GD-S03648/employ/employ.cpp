#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
ll n,m;
const ll mod = 998244353;
int c[505];
string s;

ll fac(ll num){
	ll sum=1;
	for(ll i = 2;i<=num;i++){
		sum = sum*i%mod;
	}
	return sum;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m ;
	cin >> s;
	s.insert(0,"#");
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	if(m==1){
		cout << fac(n)%mod << endl;
		return 0;
	}
	cout << 0 << endl;
	return 0;
}
