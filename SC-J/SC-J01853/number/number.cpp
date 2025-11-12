#include<bits/stdc++.h>
using namespace std;
const int maxn=+10;
string s;
vector<int> a;
bool cmp(int u,int v){
	return u>v;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]-'0'<=9 && s[i]-'0'>=0){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	if(a[0]==0){
		cout<<0;
	}
	else {
		for(int i=0;i<(int)a.size();i++){
			cout<<a[i];
		}
	}
	return 0;
}