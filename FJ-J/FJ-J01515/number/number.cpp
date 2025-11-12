#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s,a,b;
	char mx='0',mn='9';
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9') a.push_back(s[i]);
	}
	int l=a.length();
	for(int i=0;i<a.length();i++){
		if(a[i]>=mx) mx=a[i];
		if(a[i]<=mn) mn=a[i];
	}
	b.push_back(mx);
	b.push_back(mn);
	cout<<b;
	return 0;
}
