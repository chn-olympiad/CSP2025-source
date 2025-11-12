#include<bits/stdc++.h>
using namespace std;
using lld = long long;
const lld siz = 1e5+5;
const lld mod = 1e9+7;
using pll = pair<lld,lld>;

string str;
vector<lld> a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(char i:str)
		if(i<'A') a.push_back(i-'0');
	sort(a.begin(),a.end(),greater<lld>());
	for(lld i:a)
		printf("%lld",i);
	return 0;
}
