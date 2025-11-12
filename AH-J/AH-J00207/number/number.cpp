#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,less<int> > q;
string s;
int x,i;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9') q.push(s[i]-'0');
	}
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	return 0;
}
