#include<bits/stdc++.h>
using namespace std;
string s;
bool flag=0;
priority_queue<int,vector<int>,less<int> > q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			q.push(s[i]-'0');
		}
	}
	while(!q.empty()){
		if(flag==0&&q.top()==0){
			cout<<0;
			return 0;
		}
		else{
			cout<<q.top();
			q.pop();
			flag=1;
		}
	}
	return 0;
}
