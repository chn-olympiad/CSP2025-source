#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i='9';i>='0';i--){
		for(int j=0;j<s.length();j++){
			if(s[j]==i){
				cout<<s[j];
			}
		}
	}
	cout<<endl;
	return 0;
}
/*
uhh sign in problem.
quite ez i think.
plz dont give me 0pts in here 
CSP-J 2025 rp++ for all.
*/
