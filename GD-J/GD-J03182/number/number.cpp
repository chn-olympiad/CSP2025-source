#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> n;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0' && s[i]<='9')
			n.push_back(s[i]-'0');
	sort(n.begin(),n.end());
	if(n[n.size()-1] == 0)
	{
		cout<<0;
		return 0;
	}
	for(int i=n.size()-1;i>=0;i--)
		cout<<n[i];
	return 0;
}
