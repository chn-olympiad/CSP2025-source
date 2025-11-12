#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1+=s[i];
		}
	}
	sort(s1.begin(),s1.end());
	string num;
	int flag=0;
	for(int i=s1.size()-1;i>=0;i--){
		if(s1[i]!='0')flag=1;
		if(flag)num=num+s1[i];
	}
	
	cout<<num;
	return 0;
} 
