#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin >> n;
	long long a=1;
	for(int i = n;i>0;i--){
		a*=i;
		a=a % 998244353;
	}
	cout << a;
	return 0;
}
