#include<bits/stdc++.h>
using namespace std;
char s;
long long a[10000005],t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s)
	{
		if(s-'0'<10&&s-'0'>=0)
		{
			a[++t]=s-'0';
		}
	}
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--)
	{
		cout<<a[i]; 
	}
	return 0;
}
