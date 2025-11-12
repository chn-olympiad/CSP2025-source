#include<bits/stdc++.h>
using namespace std;
#define int long long
string n;
priority_queue<int>q;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]<='9'&&n[i]>='0'){
			q.push(n[i]-'0');
		}
	}
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	return 0;
} 