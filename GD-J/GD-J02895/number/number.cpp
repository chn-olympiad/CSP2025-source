#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int o = 1;
	cin >>s;
	for(int i = 0 ; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[o] = s[i]-'0';
			o++;
		}
	}
	o--;
	sort(a+1, a+o+1);
	for(int i = o;i >= 1; i--){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
