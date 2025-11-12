#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin>>s;
	long long l =s.size();
	for(int i=0;i<l;i++){
		a[s[i]-48]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}