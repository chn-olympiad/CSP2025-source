#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e5+5;
const long long mod=1e9+7;
long long mul[maxn],inv[maxn];
long long qp(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1)
		{
			res=res*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
void init()
{
	mul[0]=107;
	for(long long i=1;i<=maxn-5;i++)
	{
		mul[i]=(mul[i-1]*107)%mod;
	}
	inv[maxn-5]=qp(mul[maxn-5],mod-2);
	for(long long i=maxn-6;i>=0;i--)
	{
		inv[i]=inv[i+1]*107%mod;
	}
}
long long h[maxn];
void ha(string s)
{
	long long ss=s.size();
	h[0]=0;
	for(long long i=1;i<=ss;i++)
	{
		h[i]=(h[i-1]*107+s[i-1]-'a'+1)%mod;
//		cout<<h[i]<<' '<<s[i-1]<<' ';
	}
}
long long hh(long long x,long long y)
{
	return (h[y]-h[x-1]+mod)%mod*inv[x-1]%mod;
}
long long n,q;
map<long long,long long> mp;
string S[maxn][2],T[maxn][2];
bool check()
{
	for(long long i=1;i<=n;i++)
	{
		for(long long j=0;j<=1;j++)
		{
			long long K=S[i][j].size(),b=0;
			for(long long k=0;k<K;k++)
			{
				if(S[i][j][k]=='a'){}
				else if(S[i][j][k]=='b')
				{
					b++;
				}
				else
				{
					return false;
				}
			}
			if(b!=1)
			{
				return false;
			}
		}
	}
	for(long long i=1;i<=q;i++)
	{
		for(long long j=0;j<=1;j++)
		{
			long long K=T[i][j].size(),b=0;
			for(long long k=0;k<K;k++)
			{
				if(T[i][j][k]=='a'){}
				else if(T[i][j][k]=='b')
				{
					b++;
				}
				else
				{
					return false;
				}
			}
			if(b!=1)
			{
				return false;
			}
		}
	}
	return true;
}
//void solve()
//{
//	long long s[maxn][2],t[maxn][2];
//	long long ls[maxn],lt[maxn];
//	for(long long i=1;i<=n;i++)
//	{
//		ls[i]=S[i][0].size();
//		for(long long i=0;i<ls[i];i++)
//		{
//			if(S[i][0]=='b')
//			{
//				s[i][0]=i+1;
//				break;
//			}
//		}
//		for(long long i=0;i<ls[i];i++)
//		{
//			if(S[i][1]=='b')
//			{
//				s[i][1]=i+1;
//				break;
//			}
//		}
//	}
//	for(long long i=1;i<=q;i++)
//	{
//		lt[i]=T[i][0].size();
//		if(T[i][0].size()!=T[i][1].size())
//		{
//			lt[i]=-1;
//			continue;
//		}
//		for(long long i=0;i<lt[i];i++)
//		{
//			if(T[i][0]=='b')
//			{
//				t[i][0]=i+1;
//				break;
//			}
//		}
//		for(long long i=0;i<lt[i];i++)
//		{
//			if(T[i][1]=='b')
//			{
//				T[i][1]=i+1;
//				break;
//			}
//		}
//	}
//	for(long long _=1;_<=q;_++)
//	{
//		if(lt[i]==-1)
//		{
//			cout<<0<<'\n';
//			continue;
//		}
//		
//	}
//}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	init();
	cin>>n>>q;
	for(long long i=1;i<=n;i++)
	{
		cin>>S[i][0]>>S[i][1];
	}
	for(long long i=1;i<=q;i++)
	{
		cin>>T[i][0]>>T[i][1];
	}
//	bool c=check();
//	if(c==1)
//	{
//		solve();
//		return 0;
//	}
	string _,__;
	for(long long i=1;i<=n;i++)
	{
		_=S[i][0],__=S[i][1];
		ha(_);
		mp[h[_.size()]]=1;
//		cout<<h[_.size()]<<' ';
		ha(__);
		mp[h[__.size()]]=n+1;
//		cout<<h[__.size()]<<'\n';
	}
	string s,t;
	for(long long ___=1;___<=q;___++)
	{
		long long ans=0;
		s=T[___][0],t=T[___][1];
		long long ss=s.size(),tt=t.size();
		if(ss!=tt)
		{
			cout<<0<<'\n';
			continue;
		}
		long long a=0,b=0;
		long long ns=0,nt=0;
		for(long long i=0;i<ss;i++)
		{
			if(s[i]!=t[i])
			{
				if(ns==0)
				{
					ns=i;
				}
				nt=i;
			}
		}
		for(long long i=0;i<=ns;i++)
		{
			a=b=0;
			for(long long j=i;j<ss;j++)
			{
				a=(a*107+s[j]-'a'+1)%mod;
				b=(b*107+t[j]-'a'+1)%mod;
//				cout<<a<<' '<<s[j]<<' '<<b<<' '<<t[j]<<'\n'; 
				if(j>=nt)
				{
					long long _=mp[a],__=mp[b];
					if(_>=1&&_<=n&&__>=n+1&&__<=2*n&&_+n==__)
					{
						ans++;
//						cout<<"JJJJ\n";
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
}
