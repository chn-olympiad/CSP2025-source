#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[9],num;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i<s.size();i++){
    	int x = s[i]-'0';
    	if(x>=0 && x<=26){
    		a[x]++;
		}
	}
	string ans;
	for(int i = 9;i>=0;i--){
		for(int j = 1;j<=a[i];j++){
			ans = ans+char('0'+i);
		}
	}
	cout << ans;
	return 0;
}
