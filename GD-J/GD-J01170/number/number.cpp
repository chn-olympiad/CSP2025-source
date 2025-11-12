#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL num[100];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(LL i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			num[s[i] - '0']++;
		}
	}
	for(LL i = 9;i >= 0;i--){
		while(num[i]){
			cout << i;
			num[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
