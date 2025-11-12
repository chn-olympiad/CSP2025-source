#include<bits/stdc++.h>
using namespace std;
string s;
bool che;
priority_queue<char> q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			q.push(s[i]);
			if(s[i]!='0') che=1;
		}
	}
	if(che==0) return 0;
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	return 0;
} 
