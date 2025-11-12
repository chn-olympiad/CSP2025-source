#include<bits/stdc++.h>
using namespace std;
string a;
int as[1000086],t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a.size()-1;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			t++;
			as[t]=a[i]-'0';
		}
	}
	sort(as+1,as+1+t);
	for(int l=t;l>=1;l--)
	{
		printf("%d",as[l]);
	}
	return 0;
}
