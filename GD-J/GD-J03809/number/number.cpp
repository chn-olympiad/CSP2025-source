#include<bits/stdc++.h>
using namespace std;
int len , a[1000006];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout); 
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[len++] = s[i] - '0';
		}
	}
	sort(a , a + len);
	for(int i = len - 1; i >= 0; i--){
		cout << a[i];
	}
	return 0;
}

