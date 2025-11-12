#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005],q;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
		    a[++q]=int(s[i]-48);
		}
	}
	sort(a+1,a+1+q);
	for(int i=q;i>=1;i--)
	    cout<<a[i];
	return 0;
 } 
 
