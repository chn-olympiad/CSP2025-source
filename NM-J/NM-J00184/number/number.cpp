#include<bits/stdc++.h>
using namespace std;
string s,s1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1.push_back(s[i]);
		}
	}
	sort(s1.begin(),s1.end());
	for(int i=s.size();i>=0;i--){
		cout<<s1[i];
	}
	return 0;
}
