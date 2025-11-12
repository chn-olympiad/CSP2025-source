#include<bits/stdc++.h>
using namespace std;
int a[10000011],b[10000011],n,m,j,k,l,d,x,y,ans,sum;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')a[int(s[i]-48)]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)cout<<i;
	}
}
