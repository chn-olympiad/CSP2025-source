#include <bits/stdc++.h>
using namespace std;
int len, a[1000005];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(int i=0; i<s.size(); i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++len]=(int)(s[i]-'0');
		}
	}
	sort(a+1, a+1+len);
	for(int i=len; i>=1; i--){
		printf("%d", a[i]);
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
