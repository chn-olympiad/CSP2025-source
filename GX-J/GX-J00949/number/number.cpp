#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int a=s.size();
	sort(s[1],s[a]);
	for(int i=1;i<=a;i++){
		cout<<s[i];
	}
	cout<<s;
	
	}

	

