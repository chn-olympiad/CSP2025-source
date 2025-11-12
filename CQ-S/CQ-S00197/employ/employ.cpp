#include <bits/stdc++.h>
using namespace std;
int n,m;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	long long  cnt =1;
	for(int i = 1;i<=m;i++){
		cnt = cnt*i % 998244353;
	}
	cout<<cnt;
}


