#include<bits/stdc++.h>
using namespace std;
int t;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>t;
	cout<<((t%998244353)*3%998244353)/2%998244353;
	return 0;
}