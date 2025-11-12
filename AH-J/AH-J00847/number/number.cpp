#include<bits/stdc++.h>
using namespace std;
string a;
vector<int>v;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			v.push_back(a[i]-48);
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--)cout<<v[i];
	return 0;
}
