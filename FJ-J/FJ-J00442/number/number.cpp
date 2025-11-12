#include<bits/stdc++.h>
using namespace std;
int l,t[111111111],p;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			p++;
			t[p]=s[i]-'0';
		}
	}
	sort(t+1,t+p+1);
	for(int i=p;i>=1;i--)
	{
		cout<<t[i];
	}
	return 0;
}
