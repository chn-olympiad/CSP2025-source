#include<bits/stdc++.h>
using namespace std;

string s;
int shu[1000000+10];
int cun;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	char k;
	int shuzi=0;
	for(int i=0;i<s.length();i++)
	{
		k=s[i];
		if(k>='0' && k<='9')
		{
			shu[shuzi]=k-'0';
			shuzi++;
		}
	}
	
	sort(shu,shu+shuzi);
	
	for(int i=shuzi-1;i>=0;i--)
	{
		cout<<shu[i];
	}
	
	
	
	
	return 0;
}
