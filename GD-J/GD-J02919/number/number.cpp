#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t[15];
string st;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0;i<st.size();i++)
	{
		if('0'<=st[i]&&st[i]<='9')
		{
			t[st[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=t[i];j++) cout<<i; 
	}
	return 0;
}

