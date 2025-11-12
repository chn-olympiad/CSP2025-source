#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen('employ.in','r',stdin);
	freopen('employ.out','w',stdout);
	long long n,m,a,c=1;
	string s;
	cin >> n >> m;
	cin >> s;
	for(int i=0;i<n;i++){
		cin >> a;
	}
	if(m == n)cout << 0;
	for(int i=1;i<=n;i++){
		c *= i;
		c = c % 998244353;
	}
	cout << c;
	return 0;
}
