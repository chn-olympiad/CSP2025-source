#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=9;i>=0;i--){
		for(int l=0;l<s.size();l++){
			if(s[l]==i+'0')
				cout<<s[l];
		}
	}
	cout<<'\n';
	return 0;
}