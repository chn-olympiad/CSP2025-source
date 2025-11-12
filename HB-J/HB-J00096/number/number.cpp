#include <bits/stdc++.h>
using namespace std;
string c;
int stk[1000005],top=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	int n=c.size();
	for(int i=0;i<n;i++)
	{
		if(isdigit(c[i]))
			stk[top++]=c[i]-'0';
	}
	sort(stk,stk+top);
	for(int i=top-1;i>=0;i--)
		cout<<stk[i];
	return 0;
}
