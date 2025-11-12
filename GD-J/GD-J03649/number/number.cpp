#include<bits/stdc++.h>
using namespace std;

priority_queue<int>q;
string s;
string ans;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') q.push(s[i]-'0');
	}
	while(!q.empty()){
		ans+=(q.top()+'0');
		q.pop();
	}
	cout<<ans;
	return 0;
}
