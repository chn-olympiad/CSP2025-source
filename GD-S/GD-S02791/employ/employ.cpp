#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,m,ans=0,p=0,c[1001];
char s[1001];
bool vis[1001];
void ChaoJiBaoLi(ll x,ll s1,ll s2)
{
	if(x>n)
	{
		if(s2>=m)
		{
			ans++;
			ans%=mod;//然而没用
			return; 
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			if(s1>=c[i])
			{
				vis[i]=1;
				ChaoJiBaoLi(x+1,s1+1,s2);
				vis[i]=0;
			}
			else
			{
				if(s[x]=='1')
				{
					vis[i]=1;
					ChaoJiBaoLi(x+1,s1,s2+1);
					vis[i]=0;
				}
				else
				{
					vis[i]=1;
					ChaoJiBaoLi(x+1,s1+1,s2);
					vis[i]=0;
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	ChaoJiBaoLi(1,0,0);
	cout<<ans;
	return 0;
}

