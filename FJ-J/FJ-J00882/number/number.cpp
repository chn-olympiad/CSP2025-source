#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000005],top = 1;
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i<s.size();i++)
	{
		if(s[i] >='0'&&s[i]<='9')
		{
			n[top] = s[i]-'0';
			top++;
		}
	}
	sort(n+1,n+1+top,cmp);
	for(int i = 1;i<top;i++)
	{
		cout<< n[i];
	}
	return 0;
}
