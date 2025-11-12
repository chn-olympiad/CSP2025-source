#include<bits/stdc++.h>
#define int long long
#define lk tr[p].l+tr[p].r>>1
#define lc p<<1
#define rc p<<1|1
using namespace std;
const int N=1e6+10;
int n,k;
int arr[N];
struct Node
{
	int l,r,sum;
}tr[4*N];
void push_up(int p)
{
	tr[p].sum=tr[lc].sum^tr[rc].sum;
}
void build(int p,int l,int r)
{
	tr[p]={l,r,arr[l]};
	if(l==r)return;
	int m=lk;
	build(lc,l,m);
	build(rc,m+1,r);
	push_up(p);
}
void dfs()
{
	
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=true;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		if(arr[i]!=1)f=false;
	}
	//build(1,1,n);
	if(k==0&&f)
	{
		cout<<n/2;
	}
	else if(k==0)
	{
		int ans=0,l=0;
		for(int i=1;i<=n;i++)
		{
			if(arr[i]==0)
			{
				ans++;
				l=0;
			}
			else if(arr[i]==1&&l==0)l++;
			else if(arr[i]==1&&l==1)
			{
				ans++;
				l=0;
			}
		}
		cout<<ans;
	}
	else if(k==1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(arr[i]==1)ans++;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
