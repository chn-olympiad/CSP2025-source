#include<bits/stdc++.h>
using namespace std;
string a;
bool compare(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0' && s[i]<='9')
			a+=s[i];
	sort(a.begin(),a.end(),compare);
	cout<<a;
	return 0;
} 