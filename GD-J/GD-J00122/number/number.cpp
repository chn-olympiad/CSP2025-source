#include<bits/stdc++.h>
using namespace std;
string st;
long long a[1000000+5],k;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0;i<st.size();i++)
	{
		if(st[i]>='0'&&st[i]<='9')
		a[++k]=st[i]-'0';
	}
	sort(a+1,a+k+1);
	if(a[k]==0)
	cout<<0;
	else
	for(int i=k;i>=1;i--)
	cout<<a[i];
	return 0;
}
