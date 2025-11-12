#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long l=s.length();
	int a[100005];
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			if(s[i+1]>s[i])
			{
				swap(s[i+1],s[i]);
			}
			if(s[i]>='0'&&s[i]<='9')
			{
				cout<<s[i];
			}
		}
	}
	return 0;
}
