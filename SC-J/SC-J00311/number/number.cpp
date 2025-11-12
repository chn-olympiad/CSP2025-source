#include<bits/stdc++.h>
using namespace std;

priority_queue <int> pq;
string s;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if((s[i]-'0') >=0 && (s[i]-'0') <= 9)
			pq.push(s[i]-'0');
	}
	while(!pq.empty()){
		cout << pq.top();
		pq.pop();
	}
	return 0;
	
	fclose(stdin);
	fclose(stdout);
} 