#include<bits/stdc++.h>
using namespace std;
char a[10] = {'0','1','2','3','4','5','6','7','8','9'};
bool pd(char x){
	for(int i = 0; i <= 9; i ++){
		if(x == a[i]){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s, num;
	cin >> s;
	int lth = s.length();
	for(int i = 0; i < lth; i ++){
		if(pd(s[i])) num += s[i];
	}
	sort(num.begin(),num.end());
	lth = num.length();
	for(int i = lth - 1; i >= 0; i --){
		cout << num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}