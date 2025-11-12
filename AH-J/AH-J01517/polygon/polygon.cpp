#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,ans,b1=INT_MIN,b2;
int a[5005];
bool us[5005];
void dfs(int op,int i,int su,int mx,int k)
{
	if(i==op) 
	{
		if(su>mx*2) ans++;
		ans%=MOD;
		return;
	}
	int mmx=mx;
	for(int ii=k+1;ii<=n;ii++)
	{
		if(us[ii]) continue;
		if(a[ii]>mx) mx=a[ii];
		su+=a[ii];
		us[ii]=true;
		dfs(op,i+1,su,mx,ii);
		su-=a[ii];
		us[ii]=false;
		mx=mmx;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n<=3)
	{
		if(n<=2)
		{
			cout<<0;
			return 0;
		}
		cin>>a[1]>>a[2]>>a[3];
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int op=3;op<=n;op++)
		dfs(op,1,0,INT_MIN,0);
	for(int i=1;i<=n;i++)
	{
		b1=max(b1,a[i]);
		b2+=a[i];
	}
	if(b2>b1*2) ans++;
	cout<<ans;
	return 0;
}
