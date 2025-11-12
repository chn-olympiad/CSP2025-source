#include<bits/stdc++.h>
using namespace std;
string s,l;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int sl=s.size();
	for(int i=0;i<sl;i++){
		if('0'<=s[i]&&s[i]<='9') l+=s[i];
	}
	sort(l.begin(),l.end(),cmp);
	cout<<l;
	return 0;
}
