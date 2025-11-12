//02 
#include<iostream>
using namespace std;

long long n,m,cnt;
string s;
long long a[505];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		if (a[i]) cnt++;
	}
	long long ans = 1;
	long long ans1 = 1;
	for (int i = 1;i <= n - 1;i++){
		ans = (ans * i) % 998244353;
	}
	for (int i = 1;i <= n - cnt;i++){
		ans1 = (ans1 * i) % 998244353;
	}
	cout << ((ans * cnt) % 998244353 + ans1) % 998244353;
}
//32 
