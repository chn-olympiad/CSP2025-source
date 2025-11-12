#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	cin>>s;
	vector<int> a;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9) a.push_back(s[i]-'0');
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	for(int i=0;i<a.size();i++) cout<<a[i];
	return 0;
}