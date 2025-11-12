#include<iostream>
using namespace std;
const int mod = 998244353;

int n;

long long specialA(int x){
	long long ans = 1;
	for(int i = 2;i <= x;++i)
		ans = ans*i % mod;
	return ans;
} 

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	cout << specialA(n);
	return 0;
}
