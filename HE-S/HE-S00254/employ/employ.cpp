#include<bits/stdc++.h>

using namespace std;
const int M = 998244353;
long long n,m,c[6000],k;
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	cin >> a;
	for(int i = 1;i <= n;i ++){
		cin >> c[i];
		if(c[i] != 0 || i == 1){
			k ++;
		}
	}
	long long ans = 1;
	for(int i = 1;i <= k;i ++){
		ans = ans * i % M;
	}
	cout << ans;
	return 0;
}
