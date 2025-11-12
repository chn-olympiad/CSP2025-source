#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,less<int> >q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i]))q.push(s[i]-'0');
	}
	if(q.top()==0){
		cout<<0;
	}
	else while(!q.empty()){
		cout<<q.top();
		q.pop();
	} 
	cout<<endl;
	return 0;
}