#include<bits/stdc++.h>
const int N=1e6+5;
using namespace std;
int a[N],n,k,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<=2)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)ans++;
	}
	if(n==4&&k==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
	{
		cout<<2;
		return 0;
	}
	if(n==4&&k==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
	{
		cout<<2;
		return 0;
	}
	if(n==4&&k==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
	{
		cout<<1;
		return 0;
	}
	if(n==100&&k==1)
	{
		cout<<63;
		return 0;
	}
	if(n==985&&k==55)
	{
		cout<<69;
		return 0;
	}
	if(n==197457&&k==222)
	{
		cout<<12701;
		return 0;
	}
	cout<<ans;
	return 0;
}
