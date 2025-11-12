#include<bits/stdc++.h>
using namespace std;
string s,x;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9') x+=s[i];
	}
	sort(x.begin(),x.end(),cmp);
	cout<<x;
	return 0;
} 
