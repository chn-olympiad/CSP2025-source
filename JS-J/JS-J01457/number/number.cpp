#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,num;
bool f(char a,char b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i = 0;i < s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			num+=s[i];
		}
	}
	sort(num.begin(),num.end(),f);
	cout<<num<<"\n";
	return 0;
}