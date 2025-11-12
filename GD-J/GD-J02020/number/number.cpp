#include<iostream>
#include<queue>
using namespace std;

int len;
string s;
priority_queue<int> q;

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			q.push(s[i]-'0');
		}
	}
	
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	
	
	return 0;
} 
