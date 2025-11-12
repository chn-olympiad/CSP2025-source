#include<bits/stdc++.h>
using namespace std;
long long a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string ans = "";
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' and s[i] <= '9'){
			int x = s[i] - '0';
			a[x]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= a[i];j++){
			char z = i + '0';
			ans += z;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
