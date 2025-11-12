#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],pos= 1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.length();i ++){
		if('0' <= s[i] && s[i] <= '9'){
			a[pos ++] = s[i] - '0';
		}
	}
	sort(a + 1,a + pos,greater<int>());
	for(int i = 1;i < pos;i ++){
		cout << a[i];
	}
	return 0;
}
