#include<bits/stdc++.h>
using namespace std; 
using i64 = long long;
using PIL = pair<i64 , i64>;
const int N = 1e6 + 10;
int mian(){
	string s;
	cin >> s;
	priority_queue<i64>q;
	for(const auto &cur : s){
		if('0' <= cur && '9' >= cur)q.push(cur - '0');
	}
	while(q.size()){
		cout << q.top();
		q.pop(); 
	}
	return 0;
}
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	i64 t = 1;
//	cin >> t;
	while(t--){
		mian();
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
