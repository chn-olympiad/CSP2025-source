#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int b[1001];
    for(int i=0;i<=1001;i++)
    {
		b[i]=-1;
	}
    cin>>a;
    for(int i=1;i<=int(a.size())+1;i++)
    {
		if(a[i-1]>=48&&a[i-1]<=57)b[i]=a[i-1]-48;
		}    
	for(int i=9;i>=0;i--)
	{
		int l=0;
		for(int j=1;j<=int(a.size());j++)
		{
			if(b[j]==i)l++;
		}
		for(int k=1;k<=l;k++)
		{
			cout<<i;
		}
	}
    return 0;
}
