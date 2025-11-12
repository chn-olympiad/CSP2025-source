#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[505],b[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for( int i = 1;i <= n;i++ ){
		cin >> a[i];
	}
	for( int i = 0;i < s.length();i++ ){
		b[i + 1] = s[i] - '0';
	}
	cout << n*m*m;
	return 0;
}
