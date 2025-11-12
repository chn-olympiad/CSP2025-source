#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int len = s.length();
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i] <= '9'){
			int k = s[i] - '0';
			a[k] += 1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
