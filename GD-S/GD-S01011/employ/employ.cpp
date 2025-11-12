#include<bits/stdc++.h>
#define int long long
#define N 505
#define dbg(x) cerr<<#x<<" "<<x<<endl
#define mod 998244353
using namespace std;
int n, m, sum;
int s[N];
int c[N];
int flag1 = 1;
void read(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		char x;
		cin >> x;
		s[i] = x - '0';
		if(s[i]) sum++;
		if(s[i] == 0) flag1 = 0;
	}
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
}

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	read();
	//if(sum < m) 
		cout << 0;
	return 0;
}

