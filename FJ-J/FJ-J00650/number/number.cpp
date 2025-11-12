#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int>v;
	for(auto i:s)
	{
		if(i>='0'&&i<='9')
		{
			v.push_back(i-'0');
		}
	}
	sort(v.begin(),v.end(),greater<int>());
	for(auto i:v) cout<<i;
	cout<<endl;
	return 0;
}
