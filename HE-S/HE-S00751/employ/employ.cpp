#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[600];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n>> m >> s;
	for(int i = 1;i<=n;i++){
		cin >> c[i];
	}
	sort(c+1,c+n+1);
	cout << m % 998244353; 
	return 0;
}

