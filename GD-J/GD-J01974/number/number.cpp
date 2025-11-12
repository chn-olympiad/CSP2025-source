#include <bits/stdc++.h>
using namespace std;
int a[1000005],j = 0;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[j] = s[i] - '0';
			j++;
			
		}
	}
	sort(a,a+j+1);
	string b;
	for(int i = j; i > 0; i--){
		b += a[i] + '0';
	}
	cout << b;
	return 0;
}
