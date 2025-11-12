#include<bits/stdc++.h>
using namespace std;
int a[1000005]; 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int b=s.length(),aa=0;
	for(int i=0;i<b;i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			aa++;
			a[aa]=int(s[i])-48;
		}
	}
	sort(a,a+aa+1);
	for(int i=aa;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
