#include<bits/stdc++.h>
using namespace std;
string st;
int m,a[1000006];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0;i<st.size();i++)
		if(st[i]>='0'&&st[i]<='9')a[++m]=st[i]-'0';
	sort(a+1,a+1+m);
	for(int i=m;i>=1;i--)cout<<a[i];
	return 0;
}
