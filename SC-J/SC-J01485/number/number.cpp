#include<bits/stdc++.h>
#define int long long
#define code using
#define by namespace
#define plh std
code by plh;
int n;
string s;
vector<int>v;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end(),[&](int x,int y)
	{
		return x>y;
	});
	for(auto i:v)
	{
		cout<<i;
	}
	return 0;
}