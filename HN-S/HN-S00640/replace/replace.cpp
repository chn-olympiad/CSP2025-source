#include<bits/stdc++.h>
using namespace std;
constexpr long long N=2e5,M=1e5,V=1e18,
mod=3438625159;
long long n,m;
using ull=unsigned long long;
using ll=long long;
using ui=unsigned int;
ull hsh(const string& str)
{
	ull ret=0;
	for(auto &i:str)
	{
		ret=(ret*31+i-'a'+1)%mod;
	}
	return ret;
}
ull qpw(ull x,ull y)
{
	ull ret=1;
	for(;y;y>>=1)
	{
		if(y&1) ret=(ret*x)%mod;
		x=(x*x)%mod;
	}
	return ret%mod;
}
ull h[N+5][2];
ull w[2][N+5];
string d[N+5][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>d[i][0]>>d[i][1];
		h[i][0]=hsh(d[i][0]);
		h[i][1]=hsh(d[i][1]);
	}
	for(int T=1;T<=m;T++)
	{
		string frm,to;
		cin>>frm>>to;
		int t=frm.size();
		frm=' '+frm;
		to=' '+to;
//		{
//			ull ret1=0,ret2=0;
//			for(int i=t;i>=1;i--)
//			{
//				w[i][0]=(w[i-1][0]*31+frm[i]-'a')%mod;
//				w[i][1]=(w[i-1][1]*31+to[i]-'a')%mod;
//			}
//			
//		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			ull ret=0;
			for(int j=1;j+d[i][0].size()-1<=t;j++)
			{
				const int &r=j+d[i][0].size()-1;
				string tmp=frm;
				if(frm.substr(j,d[i][0].size())!=d[i][0]) continue;
				for(int k=j;k<=r;k++)
				{
					tmp[k]=d[i][1][k-j];
				}
//				cout<<tmp<<":w\n ";
				if(tmp==to) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

