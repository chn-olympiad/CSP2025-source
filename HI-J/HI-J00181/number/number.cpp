#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a;
	while(cin>>a)
		if(a>='0'&&a<='9')s+=a;
	sort(s.begin(),s.end(),cmp);
	cout<<s;
	return 0;
}
