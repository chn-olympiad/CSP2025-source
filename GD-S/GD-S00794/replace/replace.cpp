#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int INF = 0x3f3f3f;
#define ll long long 

int n;
string s[N][3];

int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	int q;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++){
		cin >> s[i][1] >> s[i][2];
	}
	string t1 , t2 , tx;
	int ans = 0;
	while(q--){
		cin >> t1 >> t2;
		ans = 0;
		for(int i = 1 ; i <= n ; i++){
			bool f;
			for(int j = 0 ; j < t1.length() ; j++){
				f = 1;
				for(int q = j , p = 0 ; p < s[i][1].length() ; p++ , q++){
					if(t1[q] != s[i][1][p]){
						f = 0;
						break;
					} 
				}
				if(f == 1){
					//cout << i << " " << j << endl;
					tx = t1;
					for(int q = j , p = 0 ; p < s[i][2].length() ; q++ , p++){
						tx[q] = s[i][2][p]; 
					}
					if(tx == t2){
						ans++;
					}
				} 
			}
		} 
		cout << ans << endl;
	}
	return 0;
}

/*

Ren5Jie4Di4Ling5%
*/
