#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end());
	for(int i=s.size();i>=0;i--)
	{
		if(s[i]>='0'&&s[i]<='9')
		cout<<s[i];
	}
	return 0;
}
