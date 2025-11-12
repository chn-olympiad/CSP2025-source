#include<bits/stdc++.h>
#define I_AK_CSP_J ios::sync_with_stdio(false);
using namespace std;
int n,k,cnt;
long long ans=0;
int a[100010];
bool chk(int l,int r)
{
	for(int i=l;i<=r;i++)
	{
		if(i==l)cnt=a[i];
		else cnt=cnt^a[i];
	}
	if(cnt==k)return true;
	else return false;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	I_AK_CSP_J
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(chk(i,j))ans++;
		}
	}
	cout<<ans;
	return 0;
}
