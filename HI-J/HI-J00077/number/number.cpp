#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool c(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int n=s.size();
	int q=0; 
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++q]=s[i]-'0';
		}
	}
	sort(a+1,a+q+1,c);
	for(int i=1;i<=q;i++)
	{
		cout << a[i];
	}
	return 0;
}
