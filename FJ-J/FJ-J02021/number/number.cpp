#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	int t=0;
	while(cin>>c)
	{
		if(c>='0'&&c<='9')
		{
			t++;
			a[t]=c-'0';
		}
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++)
	{
		cout<<a[i];
	}
	return 0;
}
