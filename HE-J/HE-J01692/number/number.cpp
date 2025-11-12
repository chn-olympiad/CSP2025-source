#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7+10; 
string s;
int a[maxn],maxx[maxn],cnt=-1;
bool cmp(int a,int b)
{
	return a>=b;
}
int main() 
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie();
	cin>>s;
	int len = s.size();	
	if (s.size()==1)
	{
		cout<<s;
		return 0;
	}
	len++;
	for (int i=0;i<s.size();i++)
		a[i]=-1;

	for (int i=0; i<len; i++) 
	{
		if (s[i]>='0' && s[i]<='9')
		{
			a[++cnt]=s[i]-'0';				
		}
	}
	sort(a,a+cnt,cmp);
	for (int i=0;i<=cnt;i++)
		cout<<a[i];
	return 0;
}

