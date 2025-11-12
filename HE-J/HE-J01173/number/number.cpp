#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int sum=0;
	vector<int>a;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end());
	int x=1;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=0)sum+=a[i]*x;
		x*=10;
	}
	cout<<sum;
	return 0;
}
