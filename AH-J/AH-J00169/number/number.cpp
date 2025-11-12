#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof(a));
	string s;
	cin>>s;
	int x=sizeof(s);
	while(x--)
	{
		if(s[x]<='9'&&s[x]>='0')
		{
			int b=s[x]-'0';
			a[b]++;
		}
	}
	for(int i=9;i>=0;i--)
		for(int j=1;j<=a[i];j++)
			cout<<i;
    return 0;
}
