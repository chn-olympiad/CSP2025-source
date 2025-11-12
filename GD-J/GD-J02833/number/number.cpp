#include<bits/stdc++.h>
using namespace std;
long long a[10000100],t;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (long long i=0; i<s.size(); i++){
		if (s[i]>='0' and s[i]<='9') a[++t]=s[i]-'0';
	}
	sort(a+1,a+t+1);
	for (long long i=t; i>=1; i--) cout << a[i];
	return 0;
}
