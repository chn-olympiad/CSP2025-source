#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char x;
	while(cin>>x)
	{
		if(x>='0'&&x<='9')
			a[int(x)-48]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
			cout<<i;
	}
	return 0;
}
