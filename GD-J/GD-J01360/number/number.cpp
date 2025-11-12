#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<int(s.size());i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			int x=s[i]-'0';
			a.push_back(x);
		}
	}
	sort(a.begin(),a.end(),greater<int>());
	for(int i=0;i<int(a.size());i++)
	{
		cout<<a[i];
	}
	return 0;
}
