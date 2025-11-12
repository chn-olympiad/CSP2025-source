#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
string s;
int st[N],top;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			st[++top]=s[i]-'0';
		}
	}
	sort(st+1,st+1+top);
	for(int i=top;i>=1;i--)
	{
		cout<<st[i];
	}
}
