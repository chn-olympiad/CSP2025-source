#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000100];
int a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9') n[++a]=s[i]-'0';
	sort(n+1,n+a+1);
	for(int i=a;i>0;i--)
		cout<<n[i]; 
	return 0;
} 
