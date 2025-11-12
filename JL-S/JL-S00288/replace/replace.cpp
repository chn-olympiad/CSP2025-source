#include<bits/stdc++.h>
using namespace std;
const int N=50010,mod=1e9+7,base=131;
int n,q;
char s1[1000010],s2[100010];
long long h[N],h2[N],fact[N];
map<long ,vector<long long> > mp;
long long get(int l,int r)
{
	return (h[r]-h[l-1]*fact[r-l+1]%mod+mod)%mod;
}
long long get2(int l,int r)
{
	return (h2[r]-h2[l-1]*fact[r-l+1]%mod+mod)%mod;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		long long ret=0,ret2=0;
		int x=strlen(s1);
		for(int j=0;j<x;j++)
		{
			ret=(ret*base+s1[j]-'a')%mod;
		}
		for(int j=0;j<x;j++)
		{
			ret2=(ret2*base+s2[j]-'a')%mod;
		}
		//cout<<ret<<"\n";
		mp[ret].push_back(ret2);
		mp[ret2].push_back(ret);
	}
	fact[0]=1;
	for(int i=1;i<=n;i++)
	{
		fact[i]=fact[i-1]*base%mod;
	}
	for(int i=1;i<=q;i++)
	{
		string t1,t2;
		cin>>t1>>t2;
		int x=t1.size();
		long long ans=0;
		h[0]=0;
		h2[0]=0;
		for(int i=1;i<=x;i++)
		{
			h[i]=(h[i-1]*base+t1[i-1]-'a')%mod;
		}
		for(int i=1;i<=x;i++)
		{
			h2[i]=(h2[i-1]*base+t2[i-1]-'a')%mod;
		}
		for(int i=0;i<x;i++)
		{
			string z="";
			long long y=0;
			for(int j=i;j<x;j++)
			{
				y=(y*base+t1[j]-'a')%mod;
				//if(i==0&&j==x-1) cout<<y<<"\n";
				if(mp[y].size())
				{
					for(auto k:mp[y]){
						//cout<<k<<"\n";
						if(k==get2(i+1,j+1)&&get(1,i)==get2(1,i)&&get(j+1+1,x)==get2(j+1+1,x)) ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
