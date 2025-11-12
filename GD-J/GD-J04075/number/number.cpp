#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string s;cin>>s;
	vector<int> lst(10);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') lst[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(lst[i]>0)
		{
			cout<<i;
			lst[i]--;
		}
	}
	return 0;
}
