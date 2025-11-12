#include <bits/stdc++.h> 
using namespace std;
const int N=le6+10;
int a[N],t=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.in","w",stdout);
	string s;scanf("Ad",&s);
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++t]=s[i]-'0';
		}
	}
	sort(a+1,a+t+1);
	for(int i=1;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
