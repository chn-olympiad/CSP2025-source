#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in",r,stdin);
	freopen("number.out",w,stdout);
	string s;
	cin>>s;
	string t;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')t+=s[i];
	}
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	cout<<t;
	return 0;
} 
