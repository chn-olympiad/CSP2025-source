#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	priority_queue<int> as;
	int n=s.length();
	int b=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int c=s[i]-'0';
			as.push(c);
			b++;
		}
	}
	for(int i=0;i<b;i++){
		cout<<as.top();
		as.pop();
	}
	return 0;
}