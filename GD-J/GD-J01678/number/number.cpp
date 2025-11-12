#include <bits/stdc++.h>
using namespace std;
string s;
priority_queue<int,vector<int>,less<int> >que;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		char x=s[i];
		if('0'<=x && x<='9'){
			que.push(int(x-'0'));
		}
	}
	while(!que.empty()){
		cout<<que.top();
		que.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
