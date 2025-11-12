#include <bits/stdc++.h>
#include <string>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
char L[1000006];
int main(){
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	string s;
	cin >> s;
	int k = 0;
	while (true){
		if ((s[k] - '0' >= 0 && s[k] - '0' <= 9) || (s[k] - 'a' >= 0 && s[k] - 'a' <= 25)){
			k ++;
		}
		break;
	}
	int p = 0;
	for (int i = 0; i < k; i ++){
		if (s[i] - 'a' >= 0 && s[i] - 'a' <= 25){
			int ha;
		}
		else{
			p ++;
			L[p] = s[i];
		}
	}
	sort(L+1,L+p+1,cmp);
	for (int i = 1; i <= p; i ++){
		cout << L[i];
	}
	return 0;
}
