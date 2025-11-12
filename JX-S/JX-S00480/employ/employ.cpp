#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, sum=1;
	cin>>n>>m;
	string a;
	cin>>a;
	for(int i=1; i<=n; i++){
		sum*=i;
		sum%=mod;
	}
	cout<<sum;
	return 0;
}
		
