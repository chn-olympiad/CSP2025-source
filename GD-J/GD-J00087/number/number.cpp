#include<bits/stdc++.h>
using namespace std;
string st;
int num,f[101];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0;i<st.size();i++)
	{
		if(st[i]<='9'&&st[i]>='0')
		{
			f[st[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=f[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
//1.0s,512Mib
