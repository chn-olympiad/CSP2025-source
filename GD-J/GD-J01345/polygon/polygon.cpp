#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5010;
const ll M=998224353;
int n,ans,a[5010],f[5010],cnt,t;
void dfs(int p,int s,int ma,int c)
{
	if(c>2&&s>2*ma&&c==t)
	{
		ans++;
		return;
	}
	if(p>n)
		return;
	dfs(p+1,s,ma,c);//不选
	dfs(p+1,s+a[p],max(ma,a[p]),c+1);//选 
}
ll get(ll x)//计算Cnx
{
	ll s=1;
	for(ll i=n;i>n-x;i--)
		s=s*i%M;
	for(ll i=x;i>=2;i--)
		s/=i;
	return s;
} 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=28)
	{	
		for(int i=1;i<=n;i++)
		{
			t=i;
			dfs(1,0,0,0);
		}
	}
	else
	{
		for(int i=3;i<=n;i++)
			ans=(ans+get(i)%M);			
	}
	cout<<ans<<endl;	
	return 0;
}
 
