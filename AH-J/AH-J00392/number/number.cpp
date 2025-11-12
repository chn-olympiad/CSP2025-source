#include <bits/stdc++.h>
using namespace std;
int ss;
string s;
priority_queue <int> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	ss=s.size();
	for(int i=0; i<ss; i++){
		if(s[i]>='0' && s[i]<='9')
			q.push(s[i]-'0');
	}
	if(q.top()==0){
		cout<<"0\n";
		return 0;
	}
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	cout<<"\n";
	return 0;
}
