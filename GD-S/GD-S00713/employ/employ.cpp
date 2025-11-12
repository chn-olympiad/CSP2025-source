#include<bits/stdc++.h>
using namespace std;
int n , m , ans;
int c[25] , p[25];
string s;
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 1 ; i <= n ; i++) cin >> c[i];
	for(int i = 1 ; i <= n ; i++) p[i] = i;
	do{
		int no = 0 , sum = 0;
		for(int i = 1 ; i <= n ; i++){
			if(s[i - 1] == '1' && c[p[i]] > no){
				sum++;
			}
			else no++;
		}
		if(sum >= m) ans++;
	} while(next_permutation(p + 1 , p + 1 + n));
	cout << ans % 998244353;
	return 0;
} 
