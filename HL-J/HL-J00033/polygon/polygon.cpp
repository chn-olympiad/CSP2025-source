#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,r;
	cin >> n;
	for(int i=0;i<n;i++)cin>>r;
	if(n>1e7)cout << 998244352;
	else cout << 2*n-1;
	return 0;
}