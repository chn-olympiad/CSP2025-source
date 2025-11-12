#include<bits/stdc++.h>
using namespace std;
string a;
char b[500000];
int q=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[q]=a[i];
			q++; 
		}
	}
	sort(b+1,b+q);
	for(int i=q-1;i>=1;i--)
	{
		cout<<b[i];
	}
	return 0;
}
