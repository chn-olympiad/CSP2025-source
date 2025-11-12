#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	string n;
	char a;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			n+=s[i];
		}
		else{
			continue;
		}
	}
	for(int i=0;i<n.size();i++){
		if(n[i]<n[i+1]){
			a=n[i];
			n[i]=n[i+1];
			n[i+1]=a;
		}

	}
	for(int i=0;i<n.size();i++){
		if(n[i]<n[i+1]){
			a=n[i];
			n[i]=n[i+1];
			n[i+1]=a;
		}
	}
	for(int i=0;i<n.size();i++){
		if(n[i]<n[i+1]){
			a=n[i];
			n[i]=n[i+1];
			n[i+1]=a;
		}
	}

	cout<<n;
	return 0;
}
