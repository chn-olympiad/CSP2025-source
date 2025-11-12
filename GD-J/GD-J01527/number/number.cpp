#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int b[a.size()]={},q=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			b[q]=a[i];
			q++;
		}
	}
	sort(b,b+q);
	for(int i=q-1;i>=0;i--)
	{
		cout<<b[i]-48;
	}
	return 0;
}

















































































































































































 
