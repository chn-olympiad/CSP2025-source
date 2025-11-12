#include<bits/stdc++.h>
using namespace std;	
string a;
int shu[1000001],o=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a.length()-1;i++)
	{
		if('0'<=a[i]&&a[i]<='9')
		{
			o++;
			shu[o]=a[i]-'0';
		}
	}	
	sort(shu+1,shu+o+1);
	for(int i=o;i>=1;i--)
	{
		cout<<shu[i];
	}
	return 0;
}