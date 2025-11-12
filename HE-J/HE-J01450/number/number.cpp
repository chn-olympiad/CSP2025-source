#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=1;i<=s.length();i++){
		if(s[i]<=9&&s[i]>=1){
			cout<<5;
		}
	}
	return 0;
}
