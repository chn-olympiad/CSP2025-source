#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>a;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int sz=s.size();
	for(int i=0;i<sz;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	sz=a.size();
	for(int i=0;i<sz;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
