#include <bits/stdc++.h>
using namespace std;
#define LL long long
string s;
LL cnt[100000];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	cin >> s;
	memset(cnt, 0, sizeof cnt);
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			cnt[s[i] - '0']++;
		}
	}
	bool flag = false;
	for(int i = 9; i >= 0; i--){
		if(i == 0 && flag == false){
			cout << 0;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		while(cnt[i]){
			cout << i;
			cnt[i]--;
			flag = true;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
