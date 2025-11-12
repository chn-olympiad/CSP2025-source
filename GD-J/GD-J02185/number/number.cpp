#include <bits/stdc++.h>
using namespace std;
string s,r;
priority_queue<int>q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]-'0'>=0&&s[i]-'0'<=9) q.push(s[i]);
	}
	while(!q.empty()){
		r+=q.top();
		q.pop();
	}
	cout<<r;
	return 0;
}
