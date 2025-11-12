#include <bits/stdc++.h>
using namespace std;
vector<char>v;
string s;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(isdigit(s[i])){
			v.push_back(s[i]);
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		cout<<v[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
