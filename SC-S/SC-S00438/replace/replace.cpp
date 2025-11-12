#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string s1[N] , s2[N];
inline void read(int &x){
	x = 0;
	bool f = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		f = (c == '-');
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + (c & 15);
		c = getchar();
	}
	if(f) x = -x;
}
int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	int n , q;
	cin >> n >> q;
	for(int i = 1;i <= n;++ i)
	cin >> s1[i] >> s2[i];
	for(int i = 1;i <= q;++ i){
		string t1 , t2;
		cin >> t1 >> t2;
		int ans = 0;
		for(int j = 1;j <= n;++ j){
			int b = s1[j].length() , c = s2[j].length() , d = t1.length() , e = t2.length();
			for(int k = 0;k + b - 1 < d && k + c - 1 < e;++ k){
				if(t1.substr(k , b) == s1[j] && t2.substr(k , c) == s2[j]
				&& t1.substr(min(d , k + b) , max(d - k - b , 0)) == t2.substr(k + c , e - k - c) && 
				t1.substr(0 , k) == t2.substr(0 , k)){
					++ ans;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}