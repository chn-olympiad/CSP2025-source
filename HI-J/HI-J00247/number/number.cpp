#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int sum=0;
	cin>>s;
	vector<int> x;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int c=s[i]-'0';
			x.push_back(c);
			sum++;
		}
	}
	sort(x.begin(),x.end());
	string a="";
	for(int j=0;j<sum;j++)
	{
		a+=x[j]+'0';
	}
	reverse(a.begin(),a.end());
	cout<<a;
	return 0;
} 
