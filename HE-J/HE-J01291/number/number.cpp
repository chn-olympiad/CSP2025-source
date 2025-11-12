#include<bits/stdc++.h>
using namespace std;
int main(){
	//feropen("number.in","r",stdin);
	//feropen("number.out","w",stdout);
	string s;
	stack<int>a;
	cin>>s;
	for(long i=0;i<s.size();i++){
		if(s[i]<'0'||s[i]>'9'){
			continue;
		}
        int b=(s[i]-'0');
		if(a.empty()){
            a.push(b);
            continue;
	    }
        stack<int>a2;
        while(!a.empty() && b<a.top()){
            a2.push(a.top());
            a.pop();
        }
        a.push(b);
        while(!a2.empty()){
            a.push(a2.top());
            a2.pop();
        }
	}
	while(!a.empty()){
		cout<<a.top();
		a.pop();
	}
	return 0;
}
