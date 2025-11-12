#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a;
int main()
{
	int cnt=0,p=0;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9')
	{
		cnt++;
		a.push_back(s[i]-'0');
		if(s[i]=='0') p++;
	}
	if(p==cnt)
	{
		cout<<0;
		return 0;
	}
	sort(a.begin(),a.end());
	for(int i=cnt-1;i>=0;i--) cout<<a[i];
	return 0;
}
