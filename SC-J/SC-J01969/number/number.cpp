#include<bits/stdc++.h>
using namespace std;
string a[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0'].push_back(s[i]);
		}
	}
	for(int i=9;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 