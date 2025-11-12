#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>v;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end(),cmp);
	if(v[0]==0)cout<<0<<'\n';
	else{
		for(int i=0;i<(int)v.size();i++){
			cout<<v[i];
		}
	}
	return 0;
}
