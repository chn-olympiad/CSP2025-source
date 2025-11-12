#include<bits/stdc++.h>
using namespace std;
string a;
long long f[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9') f[a[i]-48]++;
	}
	for(int i=9;i>=0;i--)
	{
		if(f[i]!=0)
		{
			for(int j=1;j<=f[i];j++) cout<<i;
		}
	}
	return 0;
}
