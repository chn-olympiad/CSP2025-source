#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=s.size();i++){
		if(isdigit(s[i])){
			q.push(s[i]-48);
		}
	}
	int flg=1;
	while(q.size()){
		if(!flg||q.top()!=0)cout<<q.top();
		else break;
		q.pop();
		flg=0;
	}
	if(flg)cout<<0;
} 
