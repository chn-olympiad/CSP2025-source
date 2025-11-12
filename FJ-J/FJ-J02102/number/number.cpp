#include<bits/stdc++.h>
#define ll long long
using namespace std;
string k;
int g[100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>k;
	for(int i=0;i<k.size();i++)
	{
		if(k[i]>='0'&&k[i]<='9')g[k[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=g[i];j++)cout<<i;
	}
	return 0;
}
