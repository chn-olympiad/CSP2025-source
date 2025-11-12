#include <bits/stdc++.h>
using namespace std;

string s, ans;
int k[10];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for(int i = 1; i <= s.size(); i ++){
		if(s[i-1] >='0' && s[i-1] <= '9'){
			k[(s[i-1]-'0')]++;
		}
	}//1e6
	for(int i = 9; i >= 0; i--){
		for(int j = 1; j <= k[i]; j++){
			if(ans.size() == 0 && i==0) 
			{
				cout << "0";
				return 0;
			}
			ans += ('0'+i);
		}
	}//1e4
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
