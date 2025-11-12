#include<bits/stdc++.h>
using namespace std;
vector<int> v; string s;
int cmp(int a,int b){return a>b;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){if(s[i]>='0'&&s[i]<='9') v.push_back(int(s[i]-'0'));}
	sort(v.begin(),v.end(),cmp);
	if(v[0]==0){cout<<0; return 0;}
	for(int i=0;i<v.size();i++) cout<<v[i];
	return 0;
}