#include<bits/stdc++.h>
using namespace std; 
string s;
int num[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long ans = 0;
	for(int i=0;i<=s.size();i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			ans = ans * 10 + (s[i] - '0');
	     } 
    } 
	cout << ans;
	return 0;
}


