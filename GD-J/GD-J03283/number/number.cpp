#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<ll> v;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') 
		{
		int as=s[i]-'0';	
		v.push_back(as);
	}
	}
	sort(v.begin(),v.end(),cmp);
	for(auto &q:v)cout<<q;
 } 
