#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],f[500005],g[2000005]; //<=2^20
ll t,tot,dp[500005],ans,tr[500005];
struct line
{
	ll x,y;
}q[500005];
bool cmp(line c,line d)
{
	return c.y<d.y;
}
ll lowbit(ll x)
{
	return x&(-x); 
}
void update(ll x,ll lm)
{
	for(ll i=x;i<=500000;i+=lowbit(i))
		tr[i]=max(tr[i],lm); 
}
ll query(ll x)
{
	ll maxx=0;
	for(ll i=x;i;i-=lowbit(i))
		maxx=max(maxx,tr[i]);
	return maxx;	
}
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
scanf("%lld %lld",&n,&k);
for(ll i=1;i<=n;i++)
	scanf("%lld",&a[i]);
g[0]=0;
for(ll i=1;i<=n;i++)	
{
	f[i]=f[i-1]^a[i];
	t=k^f[i];
	if(g[t]>0||t==0) q[++tot]={g[t]+1,i};
	g[f[i]]=i;//上一个异或和为f[i]是i 
}
sort(q+1,q+tot+1,cmp);
for(ll i=1;i<=tot;i++)
{
	t=query(q[i].x-1)+1;
	ans=max(ans,t);
	update(q[i].y,t);
}
printf("%lld",ans);
fclose(stdin);
fclose(stdout);
	return 0;
}
