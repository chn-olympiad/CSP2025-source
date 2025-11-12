#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[50100],l[1000000000];
int f(int a)
{
	int gs = 0;
	while(a)
	{
		gs++;
		l[gs] = a%2;
		a/=2;
	}
	int j = 0;
	for(int i = gs;i>=1;i--)
	{
		a += l[i]*pow(10,gs);
	}
	return a;
}
int ff(int a,int b)
{
	int er = 0;
	if(a<b)
	{
		swap(a,b);
	}
	int le = 1;
	while(a)
	{
		if(a%10!=b%10)
		{
			l[le]=1;
		}
		a/=10;
		b/=10;
		le++;
	}int sb = 0;
	for(int i = 1;i<=le;i++)
	{
		sb = l[i]*pow(2,i);
	}
	return sb;
 } 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>t;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum = 0,sh =0;;
	for(int i= 1;i<=n;i++)
	{
		for(int j = i;j<=n;j++)
		{
			for(int k =i;k<j;k++)
			{
				sh+=ff(f(a[k]),f(a[k+1]));
			}
			if(sh==t)
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
