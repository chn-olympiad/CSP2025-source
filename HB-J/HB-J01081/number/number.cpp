#include<bits/stdc++.h>
using namespace std;
char s;
int a[10000001];
bool f(int p,int q)
{
	return p>q;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int lon=0;
	while(cin>>s)
	{
		if(s>='0' and s<='9')
		{
			lon++;
			a[lon]=s-'0';
		}
	}
	sort(a+1,a+lon+1,f);
	for(int i=1;i<=lon;i++)
	{
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
