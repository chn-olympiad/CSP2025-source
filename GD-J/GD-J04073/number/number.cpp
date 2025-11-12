#include<bits/stdc++.h>
using namespace std;
priority_queue<long long>q;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]-'0'<=9){
			q.push(s[i]-'0');
		}
	}
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	return 0;
}
