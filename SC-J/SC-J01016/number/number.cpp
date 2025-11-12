#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	priority_queue<int> q;
	string s;
	cin >> s;
	for(int i = 0;s[i] != '\0';i++){
		if(s[i] >= '0' && s[i] <= '9') q.push(s[i] - '0');
	} 
	while(!q.empty()){
		int t = q.top();
		cout << t;
		q.pop();
	}
	return 0;
} 