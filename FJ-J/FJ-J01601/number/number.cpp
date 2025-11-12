#include<bits/stdc++.h>
using namespace std;
string s,a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int i;
	for(i=0;i<s.size();i++){
		if(isdigit(s[i])) a+=s[i];
	}
	sort(a.begin(),a.end());
	for(i=a.size()-1;i>=0;i--){
		cout<<a[i]; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

