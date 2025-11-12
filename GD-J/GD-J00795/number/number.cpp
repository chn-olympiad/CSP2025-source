#include <bits/stdc++.h>
using namespace std;
using LL = long long;
string s;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') cout<<s[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
