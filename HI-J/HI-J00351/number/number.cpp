#include<bits/stdc++.h>
using namespace std;
bool ans(char a,char b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	vector<char> v;
	while(cin>>c)
	{
		if(c<='9' && c>='0')v.push_back(c);
	}
	sort(v.begin(),v.end(),ans);
	for(int i=0;i<v.size();i++)
	{
		if(i==0&&v[i]=='0')
		{
			cout<<"0";
			return 0;
		}
		cout<<v[i];
	}
	return 0;
 } 
