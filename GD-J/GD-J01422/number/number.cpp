#include <bits/stdc++.h>
using namespace std;

priority_queue <int> num;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	for (int i = 0;i < s.size();i++){
		if (s[i] - '0' <=9 && s[i] - '0' >=0){
			num.push(s[i] - '0');
		}
	}
	while (!num.empty()){
		cout<<num.top();
		num.pop();
	}
	return 0;
}
