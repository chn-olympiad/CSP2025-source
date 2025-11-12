#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
char hd[N];
int c[N];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int spjC1 = 0, spjC2 = 0;
	for(int i = 1;i <= n;i++){
		cin >> hd[i];
		if(hd[i]=='1')spjC1=true;
	} 
	for(int i = 1;i <= n;i++){
		cin >> c[i];
		if(c[i] != 0)spjC2++;
	} 
	long long ans = 0;
	
	vector<int>v;
	for(int i = 1;i <= n;i++)v.push_back(i);
	do{
		int gud = 0, cnt = 0;
		int d = 1;
		for(int i : v){
			if(c[i] <= gud || hd[d] == '0')gud++;
			else cnt++;
			d++;
		}
		if(cnt >= m) ans ++;
	}while(next_permutation(v.begin(), v.end())); 
	cout << ans;
}


