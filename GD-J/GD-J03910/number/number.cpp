#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
#define ll long long
#define si short int
using namespace std;
string str;
bool flag=true;
vector<si> v;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(ll i=0;i<str.size();i++) {
		if(str[i]>='0' && str[i]<='9') {
			v.push_back(str[i]-'0');
			if(str[i]!='0') flag=false;
		}
	}
	if(flag) {
		cout<<0;
		return 0;
	}
	sort(v.begin(),v.end());
	for(ll i=v.size()-1;i>=0;i--) {
		printf("%d",v[i]);
	}
	return 0;
}
/*
290es1q0
*/

// Ô¤¼ÆµÃ·Ö100tps 
