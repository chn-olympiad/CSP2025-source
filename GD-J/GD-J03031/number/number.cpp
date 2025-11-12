#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	string s;
	cin >> s;
	int sum = 0;
	for(int i = 0; i < s.size(); i ++){
		if(s[i] <= '9'&&s[i] >= '0'){
			a[sum++] = s[i]-'0';
		}
	} 
	sort(a,a+sum);
	for(int i = sum-1; i >= 0 ; i --){
		cout << a[i];
	}
	 
	return 0;
} 
