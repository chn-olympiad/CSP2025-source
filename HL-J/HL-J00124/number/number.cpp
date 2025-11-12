#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s,t="";
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]]++;
		}
		
	}
	for(int i='9';i>='0';i--)
	{
		
		if(a[i]!=0)
		{
			while(a[i]--) cout<<i-'0';
		}
	}

	return 0;
}
