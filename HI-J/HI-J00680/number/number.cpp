#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int i;
	i=s.size();
	string n;
	while(i>0){
		if(s[i]>='0'&&s[i]<='9'){
			n=s[i];
		}
	}
	string a;
	for(int j=0;j<n.size();j++){
		a[i]=max(n[j]-'0',n[j+1]-'0');
	}
	cout<<a;
	
	
	return 0;
}
