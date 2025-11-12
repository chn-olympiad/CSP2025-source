#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int mod = 998244353;
int a[maxn];
int wait[maxn];
bool isok[maxn];
char s[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	int sum = 1;
	cin >> n >> m;
	cin >> (s+1);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if(s[i] == '1'){
			sum *= 2;
			sum %= mod;
		} 
	}
	cout << sum / 2 << endl;
    fclose(stdin);
    fclose(stdout);
	return 0;
}