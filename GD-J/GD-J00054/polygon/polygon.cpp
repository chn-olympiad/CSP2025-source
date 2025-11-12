/*
	RP++!
*/
#include<bits/stdc++.h>
using namespace std;
int rp=0x3f3f3f3f;
int n,ans;
int C(int n,int m)
{
	int x=1,y=1;
	for(int i=n;i>=n-m+1;i--) x*=i;
	for(int i=1;i<=m;i++) y*=i;
	return x/y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=3;i<=n;i++)
	{
		ans+=C(n,i);
	}
	cout<<ans;
}
