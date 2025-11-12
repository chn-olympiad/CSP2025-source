#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int c,a[100000005];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	s=" "+s;
	for(int i=1;i<=s.size();i++){
		if(s[i]-'0'>=0 && s[i]-'0'<=9)a[++c]=s[i]-'0';
	}
	sort(a+1,a+c+1);
	for(int i=c;i>=1;i--)cout << a[i];
	return 0;
} 
