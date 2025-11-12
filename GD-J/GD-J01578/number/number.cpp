#include<bits/stdc++.h>
using namespace std;
string s;
int sum;
priority_queue<int> q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	/*
	I have a friend who forget to pay the money for the CSP 2025,hahahaha.
	He tell me what he want to say,so I help him.
	He want to say:I forget to pay the money for the CSP 2025,I am bb.
	
	while True:
		print(intput())
	
	*/
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if('0'<=s[i] && s[i]<='9'){
			q.push((int)(s[i]-'0'));
			sum++;
		}
	}
	while(sum--){
		cout<<q.top();
		q.pop();
	}
	return 0;
} 
