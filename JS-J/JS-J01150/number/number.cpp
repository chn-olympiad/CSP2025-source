#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<char> a;
for(int i=0;i<s.size();i++){
	if(s[i]>='0'&&s[i]<='9'){
		a.push_back(s[i]);
	}
}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
for(int i=0;i<a.size();i++){
	cout<<a[i];
}
	return 0;
}
