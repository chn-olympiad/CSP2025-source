#include<bits/stdc++.h>
using namespace std;
string st;
int a[110];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0;i<st.size();i++)
	{
		if(st[i]<='9'&&st[i]>='0') a[st[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	for(int j=1;j<=a[i];j++)
	cout<<i;
	
	
	
	return 0;
 } 
