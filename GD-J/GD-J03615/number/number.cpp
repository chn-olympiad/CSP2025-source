#include <bits/stdc++.h>
using namespace std;

#define int long long
#define db double
#define pii pair<long long, long long>
#define endl "\n"

const int MXN = 0;

string s, ans = "";
int num[15];

signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	   
    ios::sync_with_stdio(0);
    cin.tie(0);
	   
    cin >> s;
	   
    for(int i = 0; i < s.length(); i++){
	   	if(s[i] >= '0' && s[i] <= '9'){
	   		num[s[i] - '0']++;
	    }   
    }
	
	for(int i = 9; i >= 0; i--){
		//cout << num[i] << ' ';
		for(int j = 1; j <= num[i]; j++){
		    ans += to_string(i);
        }
	}
	
	cout << ans;
	  
    return 0;
 }

