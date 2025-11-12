#include<bits/stdc++.h>
using namespace std;
long long a[10010] , t = 0;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++){
		if(int('9') >= int(s[i]) && int(s[i]) >= int('0')) a[t] = int(s[i]) - 48 , t++;
	}
	sort(a , a + t + 1);
	for(int i = t ; i > 0 ; i--){
		if(a[t] == 0){
			cout << 0;
			break;
		}
		cout << a[i];
	}
	return 0;
}