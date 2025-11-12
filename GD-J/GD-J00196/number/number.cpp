#include <bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int x=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='1'&&s[i]<='9'||s[i]=='0'){
			a[x]=s[i]-'0';
			x++;
		}
	}
	sort(a,a+x+1,greater<int>());
	for(int i=0;i<x;i++){
		cout<<a[i];
	}
	return 0;
} 
