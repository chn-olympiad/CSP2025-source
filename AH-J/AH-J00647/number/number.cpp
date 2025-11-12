#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define F std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(void){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	F;
	string s,v;
	int i;
	cin>>s;
	for(i=0;i<s.size();++i)
		if(s[i]>='0'&&s[i]<='9')v.push_back(s[i]);
	sort(v.begin(),v.end(),greater<char>());
	cout<<v<<"\n";
	return 0;
}
