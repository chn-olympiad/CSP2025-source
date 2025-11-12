#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
vector<LL> v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	LL len=s.size();
	for(LL i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9') v.push_back(s[i]-'0');
	sort(v.begin(),v.end());
	for(LL i=v.size()-1;i>=0;i--) printf("%lld",v[i]);
	return 0;
}
