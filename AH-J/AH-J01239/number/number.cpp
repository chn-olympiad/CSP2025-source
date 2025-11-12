#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,a[200];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>s;
	n=s.size();
	s='#'+s+'#';
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			m++;
			a[int(s[i]-'0')]++;
		}
	}
	if(m==a[0])
		cout<<0;
	else
	{
		for(int i=9;i>=0;i--)
		{
			while(a[i]--)
				cout<<i;
		}
	}
	return 0;
}
