#include<bits/stdc++.h>
using namespace std;
string s;
int n;
priority_queue<int> a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	while(n--){
		if(0<=(s[n]-'0') and (s[n]-'0')<=9){
		a.push(s[n]-'0');
		}
	}
	while(a.size()){
		printf("%d",a.top());
		a.pop();
	}
	return 0;
}
