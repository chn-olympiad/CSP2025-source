#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	string s;
	vector <ll> a;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a.push_back(s[i]-'0');
	}
	sort(a.begin(),a.end(),greater<ll>());
	for(int i=0;i<a.size();i++){
		cout<<a[i];
	}
	return 0;
} 
