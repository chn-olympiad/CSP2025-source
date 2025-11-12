#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6+5,base=998244353,mod=1e9+7;
int n,q,ans;
int hs1[N],hs2[N],p[M],ht1[M],ht2[M],v[M];
string s1[N];
string s2[N];
string t1,t2;
int getha1(int l,int r)
{
	return 1ll*(ht1[r]-ht1[l-1])%mod;
}
int getha2(int l,int r)
{
	return 1ll*(ht2[r]-ht2[l-1])%mod;
}
int main()
{
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	p[0]=1;
	for(int i=1;i<=M;i++)p[i]=1ll*p[i-1]*base%mod;
	for(int i=1;i<=n;i++)
	{
		hs1[0]=s1[i][0]%mod;
		hs2[0]=s2[i][0]%mod;
		for(int j=1;j<s1[i].length();j++)
		{
			hs1[i]=1ll*(hs1[i-1]+1ll*p[j]*s1[i][j])%mod;
		}
		for(int j=1;j<s2[i].length();j++)
		{
			hs2[i]=1ll*(hs2[i-1]+1ll*p[j]*s2[i][j])%mod;
		}
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>t1>>t2;
		memset(ht1,0,sizeof ht1);
		memset(ht2,0,sizeof ht2);
		ht1[0]=t1[0]%mod;
		ht2[0]=t2[0]%mod;
		for(int j=1;j<t1.length();j++)
		{
			ht1[j]=1ll*(ht1[j-1]+1ll*p[j]*t1[j])%mod;
		}
		for(int j=1;j<t2.length();j++)
		{
			ht2[j]=1ll*(ht2[j-1]+1ll*p[j]*t2[j])%mod;
		}
		for(int j=0;j<t1.length();j++)
		{
			if(t1[i]==t2[i])
			{
				v[i+1]=1;
			}
			v[i+1]=v[i]+v[i+1];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=s1[i].length();j<t1.length();j++)
			{
				int hh=getha1(j-s1[i].length(),j);
				if(1ll*hs1[i]*p[j-s1[i].length()]%mod==hh)
				{
					if((v[j-s1[i].length()+1]-v[0]==j-s1[i].length()+1)&&(v[t1.length()]-v[s1[i].length()]==t1.length()-s1[i].length()))
					{
						if(getha2(j-s1[i].length(),j)==1ll*hs2[i]*p[j-s1[i].length()]%mod)
						{
							ans++;
							ans%=mod;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
