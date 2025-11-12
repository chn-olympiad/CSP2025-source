#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	cin>>a;
	int b[1000000];
	int s=0;
	for(int i=0;i<a.size();i++)
	{
		if(isdigit(a[i]))
		{
			b[s]=a[i]-'0';
			s++;
		}
	}
	sort(b,b+s,cmp);
	for(int i=0;i<s;i++)
	{
		cout<<b[i];
	}
	return 0;
}
