#include <bits/stdc++.h>
const int N=1e6+5;
#define int  long long
using namespace std;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	priority_queue<char> q;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if((s[i]-'0'>=0)&&(s[i]-'0'<=9)){
			q.push(s[i]);
		}
	}
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
} 
