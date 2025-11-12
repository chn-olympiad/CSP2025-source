#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	vector<char>str;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')str.push_back(s[i]);
	}
	sort(str.begin(),str.end(),cmp);
	for(auto v:str)cout<<v;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
