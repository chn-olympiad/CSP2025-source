#include<bits/stdc++.h>
using namespace std;
string s;
int l,a[2000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;l=s.size();
	for(int i=0;i<l;i++)
		if(s[i]>='0' && s[i]<='9')
		{
			int x=s[i]-'0';
			a[x]++;
		}
	for(int i=9;i>=0;i--)
		if(a[i])
		{
			for(int j=1;j<=a[i];j++)
				cout<<i;
		}
	return 0;
}