#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end());
	for(int i=s.size()-1;i>=0;i--){
		if(isdigit(s[i])) cout<<s[i];
	}
	return 0;
}
