#include<bits/stdc++.h>
using namespace std;
int a[1000002],d=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	memset(a,0,sizeof(a));
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[d]=s[i]-'0';
			d++;
		}
	}
	sort(a+1,a+d);
	for(int i=d-1;i>0;i--)
	cout<<a[i];
	return 0;
 } 
