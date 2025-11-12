#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int num = 0;
	for (int i = 0;i < s.size();i++){
		if (s[i] == '9' || s[i] == '8'|| s[i] == '7'|| s[i] == '6'|| s[i] == '5'|| s[i] == '4'|| s[i] == '3'|| s[i] == '2'|| s[i] == '1'|| s[i] == '0'){
			num++;
			a[num] = s[i];
		}
	}
	sort(a + 1,a + num + 1);
	if (a[num] == '0'){
		cout << 0;
		return 0;
	}
	for (int i = num;i >= 0;i--){
		cout << a[i];
	}
	return 0;
} 
