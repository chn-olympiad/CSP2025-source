#include<bits/stdc++.h>
using namespace  std;
int a[1000006],s;
string st;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0;i<st.size();i++)
	{
		if(st[i]>='0' && st[i]<='9') a[++s]=st[i]-'0';
	}
	sort(a+1,a+1+s);
	for(int i=s;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
