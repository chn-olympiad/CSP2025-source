#include<bits/stdc++.h>
using namespace std;
int a[1000002];
int ans;
int q;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	string s1;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			q++;
			a[q]=s[i]-48;
			
		}
	}
	
	sort(a+1,a+1+q);
	for(int i=q;i>=1;i--)
	cout<<a[i];
return 0;
}
