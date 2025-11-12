#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fa tree[k]
#define ls tree[k<<1]
#define rs tree[k<<1|1]
const int N=5*1e5;
int n,k;
int he[1005][1005];
int is[1005][1005];
int a[N+5];
int dp[1005][1005],l[1005][1005],r[1005][1005];
struct node
{
	int l,r,sum;
}tree[1000];
void build(int k,int l,int r)
{
	fa.l=l,fa.r=r;
	if(l==r)
	{
		fa.sum=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(k<<1,1,mid);
	build(k<<1|1,mid+1,r);
	fa.sum=ls.sum^rs.sum;
	return ;
}
int ask(int k,int l,int r)
{
	int ans=0;
	if(fa.l>=l && fa.r<=r)
		return fa.sum;
	int mid=(fa.l+fa.r)>>1;
	if(l<=mid)
		ans^=ask(k<<1,l,r);
	if(mid+1<=r)
		ans^=ask(k<<1|1,l,r);
	return ans;
}
signed main()
{
	ios::sync_with_stdio(fale);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0)
	{
		cout<<n/2<<"\n";
		return 0;
	}
	if(k==1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],ans+=a[i];
		cout<<ans<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]==k)
			dp[i][i]=1,l[i][i]=r[i][i]=i;
	build(1,1,n);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			he[i][j]=ask(1,i,j);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(he[i][j]==k)
			{
				for(int p=1;p<=i;p++)
					for(int q=j;q<=n;q++)
						is[p][q]=1;
			}
		}
	for(int len=2;len<=n;len++)
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			int mid=(i+j)>>1;
			if(r[i][mid]!=mid && l[mid+1][j]!=mid+1)
				dp[i][j]+=is[r[i][mid]+1][l[mid+1][j]-1];
			dp[i][j]=dp[i][mid]+dp[mid+1][j];
		}
	cout<<dp[1][n]<<"\n";
	return 0;
}
