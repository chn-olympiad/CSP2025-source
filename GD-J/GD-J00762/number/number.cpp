#include<bits/stdc++.h>
using namespace std;
long long a[105];
string st;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0;i<st.size();i++)
	{
		if(st[i]>='0'&&st[i]<='9')
		{
			a[st[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i]!=0)
		{
			while(a[i]--)
			{
				cout<<i;
			}
		}
	}
	return 0;
} 
