#include<bits/stdc++.h>
using namespace std;
priority_queue<int> c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	std::cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9') c.push(s[i]-'0');
	}
	while(!c.empty()){
		std::cout<<c.top();
		c.pop();
	}
	return 0;
} 