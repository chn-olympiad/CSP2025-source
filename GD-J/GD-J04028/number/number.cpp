#include <bits/stdc++.h>
using namespace std;
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
int a[1000010],n; 
priority_queue <int> q;
int main(){
	memset(a,-1,sizeof(a));
	cin>>s;
	for(int i=0;i<s.length();i++){
		int x=s[i];
		if(x>=48&&x<=57){
			a[i]=s[i]-'0';
		}
	}
	for(int i=0;i<s.length();i++){
		if(a[i]!=-1){
			q.push(a[i]);
			n+=1;
		}
	}
	for(int i=0;i<n;i++){
		cout<<q.top();
		q.pop();
	}
	return 0;
} 
