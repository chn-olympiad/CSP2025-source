#include<bits/stdc++.h>
using namespace std;
int ans[50];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int js=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9')
		{
			ans[int(a[i])-48]++;
			js++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<ans[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
