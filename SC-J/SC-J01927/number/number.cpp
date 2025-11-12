#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int j = 1;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[j] = s[i] - '0';
			j++;
		}
	}
	sort(a + 1,a + j + 1);
	for(int i = j;i >= 2;i--){
		cout << a[i];
	}
	return 0;
}