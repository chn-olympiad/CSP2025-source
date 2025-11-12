#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>s;
	for(char i:s)
		if(isdigit(i))
			v.push_back(static_cast<int>(i-'0'));
	sort(v.begin(),v.end(),greater<int>());
	for(int i:v)
		cout<<i;
	return 0;
}
