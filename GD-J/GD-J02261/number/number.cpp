#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')cout<<s[i];
	}
}
