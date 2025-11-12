#include <bits/stdc++.h>
using namespace std;
string s;
char ans[10000007];
long long a[15], sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(long long i = 0 ; i <= s.size() ; i++){
		if(s[i] <= '9' && s[i] >= '0'){
			a[s[i]-'0']++;
			sum++;
		}
	}
	int j = 1;
	for(long long i = 9 ; i >= 0 ; i--){
		while(a[i]){
			ans[j] = i + '0';
			a[i]--;
			j++;
		}
	}
	for(long long i = 1 ; i <= sum ; i++){
		cout << ans[i];
	}
	return 0;
} 
