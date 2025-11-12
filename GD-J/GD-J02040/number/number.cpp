#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>ve;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')ve.push_back(s[i]-'0');
	}
	sort(ve.begin(),ve.end(),cmp);
	for(int i=0;i<ve.size();i++)cout<<ve[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
