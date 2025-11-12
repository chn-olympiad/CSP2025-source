#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	priority_queue<int> q;
	cin>>s;
	int cnt;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i]&&'9'>=s[i]){
			q.push(s[i]);
		}
	}
	while(q.size()){
		cout<<char(q.top());
		q.pop();
	}
	return 0;
}
