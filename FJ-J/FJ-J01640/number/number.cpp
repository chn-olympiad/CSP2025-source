#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int f=1;
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			a[f]=(s[i]-'0');
			f++;	
		}
	}
	sort(a+1,a+f+1);
	for(int i=f;i>1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
