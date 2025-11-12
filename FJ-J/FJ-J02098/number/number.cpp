#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
 } 
int main()
{
	freopen("number.out","w",stdout);
	freopen("number.in","r",stdin);
	string s;
	cin>>s;
	int a[s.size()]={0};
	int tot=0;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[i]=s[i]-'0';
			tot++;
		}
	}
	sort(a,a+s.size(),cmp);
	for(int i=0;i<tot;i++)
	{
		cout<<a[i];
	}
	return 0;
}
