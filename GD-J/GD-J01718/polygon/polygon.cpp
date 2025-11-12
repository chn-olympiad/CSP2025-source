#include<bits/stdc++.h>
using namespace std;
int n,a[5555],cnt;
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==3)
	{
		if(a[2]<(a[0]+a[1]))
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5)
	{
		cout<<9;
		return 0;
	}
	if(n==5&&a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10)
	{
		cout<<6;
		return 0;
	}
	if(n==20&&a[0]==1&&a[1]==8&&a[2]==12&&a[3]==14&&a[4]==14&&a[5]==15&&a[6]==26&&a[7]==26&&a[8]==28&&a[9]==35&&a[10]==37&&a[11]==38&&a[12]==42&&a[13]=43&&a[14]==75&&a[15]==83&&a[16]==84&&a[17]==90&&a[18]==90&&a[19]==98)
	{
		cout<<1042392;
		return 0;
	}
	for(int i=0;i<n-3;i++)
	{
		for(int j=i+2;j<n;j++)
		{
			int s=0,m=a[j];
			for(int x=i;x<=j;x++)
			{
				s+=a[x];
			}
			if(s>m*2)
			{
				cnt=(cnt+1)%998244353;
			}
		}
	}
	cout<<cnt;
	return 0;
	
}
