#include<bits/stdc++.h>
using namespace std;
string s;
int n,stk[1000100],top;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
			stk[++top]=s[i]-48;
	}
	sort(stk+1,stk+1+top);
	for(int i=top;i>=1;i--)
		cout<<stk[i];
	cout<<"\n";
}