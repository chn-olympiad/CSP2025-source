#include<bits/stdc++.h>
using namespace std;
string st;
long long a[1000005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long ii=0;
	cin>>st;
	for (int i=0;i<st.size();i++)
	{
		if (st[i]>='0'&&st[i]<='9')
		{
			a[ii]=st[i]-'0';
			ii++;
		}
	}
	sort(a,a+ii);
	for (int i=ii-1;i>=0;i--) cout<<a[i];
	return 0;
}