#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	vector<int> n;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') n.push_back(s[i]-'0');
	}
	sort(n.begin(),n.end());
	for(long long i=n.size()-1;i>=0;i--)
	{
		cout<<n[i]; 
	}
	return 0;
	
}

