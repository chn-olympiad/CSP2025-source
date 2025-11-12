#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int> a;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		int v=s[i];
		if(v>=48&&v<=57)
		{
			a.push_back(v-48);
		}
	}
	sort(a.begin(),a.end()); 
	for(int i=a.size()-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
