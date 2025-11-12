#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll l=s.size();
	sort(s.begin(),s.end(),cmp);
	bool f=0;
	for(ll i=0;i<l;i++){
		if(s[i]<'0'||s[i]>'9') continue;
		if(s[i]=='0'&&!f){
			cout<<0;
			break;
		}
		cout<<s[i];
	}
	return 0;
}
