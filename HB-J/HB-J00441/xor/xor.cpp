#include<bits/stdc++.h>
using namespace std;
int n,k,li[900000],cnt,bny[10000],flag=0,ca;
int  sz(int a)
{
	int shu=0;
	for(int j=1;j<=a;j++)
	{
		shu+=li[j];
	}
	return shu;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>li[i];
		if(li[i]==k)
		{
			cnt++;
			bny[cnt]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(sz(i)==k)
		{
			cnt++;
			break;
		}
		else if(sz(i)>k)
		{
			ca=sz(i)-k;
			for(int j=1;j<=i;j++)
			{
				if(i>=bny[i])
				{
					flag=1;
				}
			}
			for(int j=1;j<=i;j++)
			{
				if(li[j]==ca&&flag==0)
				{
					cnt++;
				}
			}
			flag=0;
		}
	}
	cout<<cnt;
	return 0;
}
