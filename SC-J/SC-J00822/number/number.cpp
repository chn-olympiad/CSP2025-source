#include <bits/stdc++.h>
using namespace std;
char a[1000010];
int b[10];
int main()
{

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int i=0;
	while(a[i]!='\0')
	{
		if(a[i]<'A')
		{
			b[a[i]-'0']++;	
		}
		i++;
	}

	for(i=9;i>=0;i--)
	{
		while(b[i]!=0)
		{
			cout<<i;
			b[i]--;
		}
	}
	return 0;
 } 