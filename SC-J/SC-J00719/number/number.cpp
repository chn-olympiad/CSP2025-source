#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end(),cmp);
	bool f = 1;
	for(int i=0;i<v.size();i++){
		if(v[i]!=0) f = 0;
	} 
	if(f) cout<<0;
	else for(int i=0;i<v.size();i++) cout<<v[i];
	return 0;
} 