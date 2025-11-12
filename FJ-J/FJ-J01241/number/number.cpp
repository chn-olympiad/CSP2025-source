#include<bits/stdc++.h>
using namespace std;
priority_queue <int>q;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++){
		if(s[i]>=4&&s[i]<=57){
			q.push(s[i]-48);
		}	
	}	
	while(!q.empty()){
		int b=q.top();
		q.pop();
		cout<<b;
	} 
	return 0;
} 
