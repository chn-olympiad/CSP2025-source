#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
vector<int> v;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
		if(s[i]>='0'&&s[i]<='9')
			v.push_back(s[i]-'0');
	sort(v.begin(),v.end(),greater<int>());
	if(v[0]==0)
		cout<<0;
	else
		for(int a:v)
			cout<<a;
	return 0;
}
