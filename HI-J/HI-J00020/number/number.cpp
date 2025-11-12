#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long string s;
	cin >> s;
	long long a[s.length()],num=0;
	for (int i=0;i<s.length();i++){
		if (s[i]<='9'&&'0'<=s[i]){
			a[num]=s[i]-'0';
			num++;
		}
	}
	sort(a,a+num);
	for (int i=num-1;i>=0;i--){
		cout << a[i];
	}
	return 0;
}
