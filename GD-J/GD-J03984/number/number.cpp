#include <bits/stdc++.h>
using namespace std;

int a[100005];
bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	memset(a, -1, sizeof(a));
	int next=1;
	string s;
	cin >> s;
	for (int i = 0; i <= s.size(); i++){
		if (s[i] >= '0' && s[i] <= '9'){
			a[next] = s[i]-'0';
			next++;
		}
	}
	sort(a+1, a+s.size()+1, cmp);
	for (int i = 1; i <= s.size(); i++){
		if (a[i] < 0){
			break;
		}
		cout << a[i];
	}
	return 0;
} 
