#include<bits/stdc++.h>
using namespace std;
int a[100001][4];
int ls=3,a1=0,a3=0,a2=0,n,k;
int dp[100010][4];
int b[100001];
bool tp(int a22,int a33)
{
	if(a22==0&&a33==0)
	{
		for(int i=1;i<=n;i++)
			b[i]=a[i][1];
		sort(b+1,b+n+1);
  		for(int j=n;j>=n/2;j--)
			k=k+b[j];
		return 1;
	}
	return 0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int b=1;b<=t;b++)
	{
		cin>>n;
 		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a2=max(a[i][2],a2);
			a3=max(a[i][3],a3);
			dp[i][1]=a[i][1];
		}
		if(tp(a2,a3)) cout<<k<<endl;
	}
	return 0;
}
