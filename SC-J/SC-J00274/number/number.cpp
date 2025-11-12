#include<bits/stdc++.h>
using namespace std;
string a;
int s,b[10]={0},q,c=0;
int main()
{
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	s=a.size();
	for(int i=0;i<s;i++) if(a[i]<='9'&&a[1]>='0')
    {
		b[q]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<b[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
} 