#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	long long a[100005], b;
	b = 0;
	for(int i = 0; i <= s.size()- 1; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[i] = s[i] - '0';
			b++;
		}else{
			continue;
		}	
	}
	for(int i = 1; i <= b; i++){
		for(int i = 1; i <= b - 1; i++){
			if(a[i] >= a[i - 1]){
				swap(a[i], a[i - 1]);
			}
		}
	}
	for(int i = 0; i <= b - 1; i++){
		cout << a[i];
	}
	return 0;
} 
