#include<bits/stdc++.h>
using namespace std;
priority_queue <int> q;
string s;
int sum = 1;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(isdigit(s[i])){
			q.push(s[i] - '0');
			sum++;
		}
	}
	while(--sum){
		printf("%d", q.top());
		q.pop();
	}
	return 0;
} 