#include<bits/stdc++.h>
using namespace std;
bool s(int a,int b)
{
	return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int a[99999],o=0;
	for(int i=0;i<n.size();i++)
	{
		if(int(n[i])>='0'&&int(n[i])<='9')
		{
			a[o]=n[i]-'0';
			o++;
		}
	}
	sort(a,a+o,s);
	for(int i=0;i<o;i++)
	{
		cout<<a[i];
	}
	return 0;
}