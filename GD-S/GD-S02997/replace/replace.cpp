#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
const int M=5e6;
const long long B=131;
const long long mod=998244353;
int n,q,maxx,cnt,id;
long long p[M+5],ans,ha[M+5],ha2[M+5];
string s[N+5],x[N+5],a,b,c,d;
vector<long long>h[N+5],h2[N+5];
long long Hashh(int now,int l,int r)
{
	return (h[now][r]-(h[now][l-1]*p[r-l+1]%mod)+mod)%mod;
}
long long Hashh2(int now,int l,int r)
{
	return (h2[now][r]-(h2[now][l-1]*p[r-l+1]%mod)+mod)%mod;
}
long long Hashha(int l,int r)
{
	return (ha[r]-(ha[l-1]*p[r-l+1]%mod)+mod)%mod;
}
long long Hashha2(int l,int r)
{
	return (ha2[r]-(ha2[l-1]*p[r-l+1]%mod)+mod)%mod;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>x[i];maxx=max(maxx,(int)(s[i].size()));
		h[i].push_back(0);h2[i].push_back(0);
		for(int j=1;j<=s[i].size();j++)
		{
			h[i].push_back((h[i][j-1]*B%mod+s[i][j-1])%mod);
			h2[i].push_back((h2[i][j-1]*B%mod+x[i][j-1])%mod);
		}
	}
	p[0]=1;
	for(int i=1;i<=maxx;i++) p[i]=p[i-1]*B%mod;
	while(q--)
	{
		cin>>a>>b;cnt=0;ans=0;
		if(a.size()!=b.size()){cout<<"0\n";continue;
		}
		for(int i=0;i<a.size();)
		{
			if(a[i]!=b[i])
			{
				cnt++;id=i+1;c="",d="";
				while(i<a.size()&&a[i]!=b[i]) ha[i+1]=(ha[i]*B%mod+a[i])%mod,ha2[i+1]=(ha2[i]*B%mod+b[i])%mod,c+=a[i],d+=b[i],i++;
			}
			else
			{
				ha[i+1]=(ha[i]*B%mod+a[i])%mod;
				ha2[i+1]=(ha2[i]*B%mod+b[i])%mod;
			}
		}
		if(cnt>1){cout<<"0\n";continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=s[i].size();j++)
			{
				if(Hashh(i,j,j+c.size()-1)==Hashha(id,id+c.size()-1)&&Hashh2(i,j,j+c.size()-1)==Hashha2(id,id+c.size()-1))
				{
					if(Hashh(i,1,j-1)==Hashha(id-j+1,j-1)&&Hashh2(i,1,j-1)==Hashha2(id-j+1,j-1)&&Hashh(i,j+c.size(),s[i].size())==Hashha(id+c.size(),id+c.size()+(s[i].size()-j-c.size()))&&Hashh2(i,j+c.size(),s[i].size())==Hashha2(id+c.size(),id+c.size()+(s[i].size()-j-c.size()))) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
