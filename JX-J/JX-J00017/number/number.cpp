#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],topa;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=s.size();
	for(int i=0;i<k;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[++topa]=s[i]-'0';
		}
	}
	sort(a+1,a+topa+1);
	for(int i=topa;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
