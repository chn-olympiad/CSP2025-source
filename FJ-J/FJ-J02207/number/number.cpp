#include<bits/stdc++.h>
using namespace std;
string s;
bool comp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='a'&&s[i]<='z'){
			s.erase(i,1);
			i--;
		}
	sort(s.begin(),s.end(),comp);
	cout<<s;
	return 0;
}
