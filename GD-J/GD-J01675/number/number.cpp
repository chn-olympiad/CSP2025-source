#include<bits/stdc++.h>
using namespace std;
char c;
int a[1000005],t;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);	
	freopen("number.out","w",stdout);
	while(cin>>c)
	{
		if(c>='0'&&c<='9')a[++t]=int(c)-48;
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++)
		cout<<a[i];
	return 0;
}
