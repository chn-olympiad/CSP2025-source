#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	priority_queue<int> a;
	cin>>s;
	for(auto i:s){
		if(i>='0'&&i<='9') a.push(i-'0');
	}
	while(!a.empty()){
		cout<<a.top();
		a.pop();
	}
	return 0;
}

