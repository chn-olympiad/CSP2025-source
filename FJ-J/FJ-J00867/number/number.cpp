#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("r","number.in",stdin);
	freopen("w","number.out",stdout);
	string s;
	cin >> s;
	int a[10] = {};
	for(int i=0;i<s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[s[i]- '0']++;
		}
	}
	for(int j=9;j>=0;j--){
		for(int i=1;i<=a[j];i++){
			cout << j;
		}
	}
	return 0;
}















































