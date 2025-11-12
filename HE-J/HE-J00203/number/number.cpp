#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1000005],q=0;
	for(int i=0;i<s.length();i++)
	{
		if(!97<=s[i]<=122)
		{
			a[q]=s[i]-132+1;
			q++;
		}
	}
	sort(a,a+q);
	for(int i=q-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
 } 
