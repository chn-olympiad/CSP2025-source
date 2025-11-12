#include<bits/stdc++.h>
using namespace std;
int n,a[100],t=0;
string x;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	n=x.size()-1;
	for(int i=0;i<=n;i++)
	{
		if(x[i]<='9' && x[i]>='0')
		{
			a[x[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
