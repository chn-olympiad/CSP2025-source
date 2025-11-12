#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;
	int c=0;
	cin>>s; 
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			a[i]=s[i]-'0';
			c++;
		}
	}
	sort(a+0,a+c,cmp);
	for(int i=0;i<c;i++)
	{
		cout<<a[i];
	} 
	
	return 0;
} 
