#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
const int mod=998244353;
ll n,m;
string s;
ll a[N],b[N],c[N],d[N];
ll po;
ll shiye,luqu;
ll f,ans;
ll qwq[N];
void dfs(ll x)
{
	if(x>n)
	{
		/*for(int i=1;i<=n;i++)
		{
			cout<<qwq[i]<<" ";
		}
		cout<<"\n";*/
		if(luqu>=m)ans++;
		ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		//if(qwq[1]==1&&i==2)cout<<shiye<<" "<<d[i]<<" "<< luqu<<"\n";
		if(shiye<a[i]&&d[i]==0)
		{
			if(b[x]==1)luqu++;
			if(b[x]==0) shiye++;
			d[i]=1;
			qwq[x]=i;
			dfs(x+1);
			if(b[x]==1)luqu--;
			if(b[x]==0) shiye--;
			d[i]=0;
		}
	}
	
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[a[i]]++;
	}
	for(int i=0;i<s.size();i++)
	{
		b[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)po++;
	}
	if(n-po<m)
	{
		cout<<0;
	} 
	else
	{
		if(c[1]==n)
		{
			ll sum=1;
			for(int i=1;i<=n;i++)
			{
				if(b[i]==0)
				{
					if(i<m)
					{
						cout<<0;
						return 0;
					}
					break;
				}
				sum=sum*c[1]%mod;
				c[1]--;
			}
			cout<<sum;
			return 0;
		}
		dfs(1);
		cout<<ans;
	}
	return 0;
}

