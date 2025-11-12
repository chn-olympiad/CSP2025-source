#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	n=s.size();
	if(n==1){
		cout<<s;
	}else if(n==2){
		if(s[0]>s[1]){
			cout<<s;
		}else{
			cout<<s[1]<<s[0];
		}
	}
	return 0;
}
