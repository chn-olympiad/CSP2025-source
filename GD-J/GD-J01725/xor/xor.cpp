#include<bits/stdc++.h>
#define int long long
using namespace std;
const int zzz=252525;
int n,k,t,len,ans,a[zzz],sum[zzz];
map <int,int> vis;
struct ff{
	int x,y;
}f[zzz];
bool cmp(ff a,ff b)
{
	if(a.x!=b.x) return a.x<b.x;
	else return a.y<b.y;
}
queue <ff> q;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
	cin>>n>>k>>a[1];
	int s0=0,s1=0;
	if(a[1]==1) s1++;
	if(a[1]==0) s0++;
	sum[0]=0,sum[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0) s0++;
		if(a[i]==1) s1++;
		sum[i]=sum[i-1]^a[i];
	}
	if(s1==n) cout<<(k==1?max(s1,1ll):n/2),exit(0);
	if(s1+s0==n)
	{
		if(k==1) cout<<s1;
		else cout<<(s1/2)+s0;
		exit(0);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int dick=sum[j]^sum[i-1];
			if(dick==k)
			{
				f[++t].x=i,f[t].y=j;
				break;
			}
		}
	}
	sort(f+1,f+t+1,cmp);
//	for(int i=1;i<=t;i++) cout<<f[i].x<<" "<<f[i].y<<"\n";
	f[t+1].x=n+1;
	for(int i=1;i<=t;i++)
	{
		if(f[i].y>=f[i+1].x)
		{
			if(abs(f[i].y-f[i].x)>abs(f[i+1].y-f[i+1].x)) continue;
		}
		ans++;
	}
	cout<<ans;
	return 0;
}
