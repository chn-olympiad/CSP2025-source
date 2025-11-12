#include<bits/stdc++.h>
using namespace std;
int n,b[10000000],ma=INT_MIN;
string a;
char m;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int k=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			n+=1;
			b[a[i]-'0']+=1;
		}
	}
	for(int i=100000;i>=0;i--)
	{
		if(b[i]!=0)
		{
			for(int j=0;j<b[i];j++)printf("%d",i);
		}
	}
	return 0;
}
