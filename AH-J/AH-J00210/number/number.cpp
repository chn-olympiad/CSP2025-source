#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
map <int, int> mp;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

	cin >> s;
	int n = s.size();
	for(int i = 0;i < n;i++)
        if('0' <= s[i] && s[i] <= '9')
            mp[s[i]-'0']++;
    for(int i = 9;i >= 0;i--){
        for(int j = 0;j < mp[i];j++)    cout << i;
    }
        
    return 0;
}
