#include<bits/stdc++.h>
using namespace std;
long long i,j,p[100],m;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();i++)if(s[i]>='0'&&s[i]<='9')
	{
		p[s[i]-'0']++;
		m++;
	}
	for(i=9;i>=0;i--)
	{
		if(p[i]!=0)
		{
			if(i==0&&p[i]==m)
			{
				cout<<"0";
				break;
			}
			for(j=1;j<=p[i];j++)cout<<i;
		}
	}
	return 0;
}