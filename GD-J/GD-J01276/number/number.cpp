#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int a[1000011];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size(),q=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[q]=s[i]-'0';
			q++;
		}
	}
	sort(a,a+q,cmp);
	for(int i=0;i<q;i++)
	{
		cout<<a[i];
	}
	return 0;
}
