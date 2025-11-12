#include<bits/stdc++.h>
using namespace std;
string s;
int a,b;
priority_queue<int>q;
int cnt=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>'0'&&s[i]<='9'){                        
		    q.push(s[i]-48); 
			b++;	
		}
		if(s[i]=='0'){
			a++;
		}
	}
	for(int i=1;i<=b;i++){
		cout<<q.top();
		q.pop();
	}
	for(int i=1;i<=a;i++){
		cout<<"0";
	}
	return 0;
} 
