#include <bits/stdc++.h>
using namespace std;
long long a[20];
string s;
string s2;
long long len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len = s.size();
	memset(a,0,sizeof a);
	for (long long i = 0 ; i < len ; i ++ ){
		if(s[i]>'9'|| s[i]<'0') continue;
		if (s[i] - '0' >= 0 && s[i]-'0'<=9){
			a[s[i]-'0']++;
		}
	}
	for (long long i = 9 ; i>= 0 ; i --) {
		for (long long j = 1 ; j <= a[i]; j ++ ){
			s2 += i + '0';
		}
	}
	cout << s2 << endl;
	return 0;
}
