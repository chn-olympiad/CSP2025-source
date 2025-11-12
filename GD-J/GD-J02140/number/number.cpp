#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	string str;
	cin >> str;
	long long n[str.size()];
	long long idx = 0;
	for(int i = 0;i < str.size();i ++){
		if(str[i] - '0' <= 9 && str[i] - '0' >= 0){
			n[idx] = str[i] - '0';
			idx ++;
		}
	}
	sort(n,n+idx);
	for(long long i = idx-1;i >= 0;i --){
		cout << n[i];
	}
	return 0;
}
