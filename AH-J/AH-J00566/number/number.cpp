#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<long long> a;
	long long n=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a.push_back(s[i]-'0');
			n++;
		}
	}
	sort(a.begin(),a.end());
	for(int i=n-1;i>=0;i--)
	{
		printf("%lld",a[i]);
	}
	return 0;
}
