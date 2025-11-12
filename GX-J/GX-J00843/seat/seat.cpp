#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w".stdout);
	int n,m,a,s[101],b=1,c;
	cin>>n>>m;
	a=n*m;
	for(int i=1;i<=a;i++)
	{
		cin>>s[i];
		if(s[i]>s[1]) b++;
	}
	c=b/n;
	if(b%n!=0) c++;
	if(c%2==0)
	{
		if(b<=n) cout<<c<<' '<<b<<endl;
		else
		{
			cout<<c<<' '<<b%n<<endl;
		}
	}
	else
	{
		a=n-(b%m);
		cout<<c<<' '<<a<<endl;
	}
	return 0;
}
