#include<bits/stdc++.h>
using namespace std;
long long a[1000005],n;
string st;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0;i<st.size();i++)
	{
		if(st[i]>='0'&&st[i]<='9')
		a[st[i]-48]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		cout<<i;
	}
	return 0;
}
