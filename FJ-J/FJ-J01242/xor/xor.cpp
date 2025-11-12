#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],d[500005]={0},s[1003][1003];
bool flag[5];
void f1()
{
	if(s[1][1]==0)
	for(int i=1;i<=n;i++)
	{
		s[i][i]=a[i];
		for(int j=i+1;j<=n;j++)
		{
			s[i][j]=s[i][j-1] xor a[j];
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			int bjd=0;
			if(s[j][i]==k)bjd=1;
			d[i]=max(d[j-1]+bjd,d[i]);
		}	
	}
	cout<<d[n];
	return ;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!flag[0])
		{
			if(a[i]!=1)
			flag[0]=1;
		}
	}
	if(!flag[0])
	{
		cout<<n/2;
		return 0;
	}
	f1();
	return 0;
} 
