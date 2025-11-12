#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+5;
long long a[N],k;
string res;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[k]=(int)(s[i]-'0');
			k++;
		 } 
	}
	for(int j=9;j>-1;j--)
	{
		for(int i=0;i<k;i++)
		{
			if(a[i]==j)
			{
				cout<<a[i];
			}
		}
	}
	return 0;
 } 