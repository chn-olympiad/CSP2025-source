#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],pre[500005],cnt1;
bool flag1=1,flag2=1,vis[500005];
bool check(int l,int r)
{
	for(int i=l;i<=r;i++)
		if(vis[i]==1)return 1;
	return 0;
}
void change_vis(int l,int r)
{
	for(int i=l;i<=r;i++)
		vis[i]=1;
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		flag1=(a[i]==1?flag1:0);
		flag2=(a[i]==1||a[i]==0?flag2:0);
		cnt1+=a[i]==k;
		vis[i]=a[i]==k;
		pre[i]=pre[i-1]^a[i];
	}
	if(flag1)
		cout<<n/2;
	if(flag2)
		cout<<cnt1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			if((pre[j+i-1]^pre[j-1])==k&&!check(j,j+i-1))
				cnt1++,change_vis(j,j+i-1);
		}	
	}
	cout<<cnt1;
	return 0;
}