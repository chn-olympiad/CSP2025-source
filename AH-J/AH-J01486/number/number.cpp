#include<bits/stdc++.h>
using namespace std;
string str,rst;
map<long long,long long> a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(long long i=0;i<str.size();i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			a[str[i]-'0']++;
		}
	}
	for(auto e:a)
	{
		string cf(e.second,char(e.first+'0'));
		rst+=cf;
	}
	reverse(rst.begin(),rst.end());
	while(rst.size()>1&&rst[0]=='0')rst.erase(0,1);
	cout<<rst;
}
