#include<bits/stdc++.h>
using namespace std;
char a[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string b="";
	int i=1,t=0;
	while(cin>>a[i])
	i++;
	int n=i;
	sort(a+1,a+n+1);
	for(i=n;i>=1;i--)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b+=a[i];
			t++;
		}
	}
	cout<<b;
	return 0;
}
