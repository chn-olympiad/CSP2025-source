#include<bits/stdc++.h>
using namespace std;
int a[15];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int s1=s.size();
	for(int i=0;i<s1;i++)
	{
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i])
		{
			for(int j=a[i];j>0;j--)
			{
				cout<<i;
			}
		}
	}
	
    return 0;
}
