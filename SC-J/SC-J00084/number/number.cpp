#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
string s;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> s;
	for(int i=0;i<s.size();++i){
		if(s[i]<='9'&&s[i]>='0'){
			pq.push(s[i]-'0');
		}
	}
	
	while(!pq.empty()){
		cout << pq.top();
		pq.pop();
	}
	cout << endl;
	
	return 0;
}