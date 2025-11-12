#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l,r;
};
node f[500005];
bool bitk[30],bitx[30];
int cnt[2500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,x=0,a,t,tot=0,m,ans=1;
	memset(cnt,-0x3f,sizeof cnt);
	cnt[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		x^=a;
		t=x^k;
		if(cnt[t]>=0)
		{
			f[tot].l=cnt[t]+1;
			f[tot++].r=i;
		}
		cnt[x]=i;
	}
	if(tot==0)
	{
		cout<<0;
		return 0;
	}
	m=f[0].r;
	for(int i=1;i<tot;i++)
	{
		if(f[i].l>m)
		{
			m=f[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
