#include<bits/stdc++.h>
using namespace std;
#define int long long 
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	vector<int>vect; 
	string str;cin>>str;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]-'0'<=9&&str[i]-'0'>=0)
		{
			vect.push_back(str[i]-'0');
		}
	}
	sort(vect.begin(),vect.end(),cmp);
	for(auto tmp:vect)cout<<tmp;
}
