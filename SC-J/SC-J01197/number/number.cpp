#include<bits/stdc++.h>
using namespace std;
int nu[1000006];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	int tot=0;
	for(int i=0;i<=l-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			tot++;
			nu[tot]=s[i]-'0';
		}
	}
	sort(nu+1,nu+tot+1,cmp);
	for(int i=1;i<=tot;i++)
	{
		cout<<nu[i];
	}
	return 0;
}