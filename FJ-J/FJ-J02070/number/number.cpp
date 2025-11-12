#include<bits/stdc++.h>
using namespace std;
int b[1000001];
string a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int i,s=0;
	for(i=0;i<a.size();i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			s++;
			b[s]=a[i]-'0';
		}
	}
	sort(b+1,b+s+1);
	for(i=s;i>=1;i--)
	{
		cout<<b[i];
	}
}
