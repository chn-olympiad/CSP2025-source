#include<bits/stdc++.h>
using namespace std;
int b[1000010],maxn=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
			b[a[i]-'0']++;
		if(a[i]>='0'&&a[i]<='9')
			if(a[i]-'0'>maxn)
				maxn=a[i]-'0';
	}
	for(int i=maxn;i>=0;i--)
	{
		if(b[i]!=0)
		{
			for(int j=1;j<=b[i];j++)
				cout<<i;
		}
	}
	return 0;
}
