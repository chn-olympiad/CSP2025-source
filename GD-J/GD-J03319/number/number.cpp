#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
vector<int>a;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(isdigit(s[i]))a.push_back((s[i]-'0'));
	}
	sort(a.begin(),a.end(),greater<int>());
	for(int i=0;i<(int)a.size();i++)cout<<a[i];
	return 0;
}
