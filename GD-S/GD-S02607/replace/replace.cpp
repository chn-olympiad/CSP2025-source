#include<bits/stdc++.h>
#define ll long long
#define pb push_back


using namespace std;

const int N=2e5+10;
int n,q;
string s[N][2];
string t[N][2];

int cnts=0,cntt=0;
int tos[N][2];
int tot[N][2];
vector<unsigned ll> sums[N<<1];
vector<unsigned ll> sumt[N<<1];

unsigned ll B=233;

unsigned ll mypow(unsigned ll a,int b)
{
	unsigned ll sum=1,A=a;
	while(b)
	{
		if(b%2==1)
		{
			sum*=A;
		}
		A*=A;
		b>>=1;
	}
	return sum;
}

int ck(int i,int x,int y)
{
	if(t[i][1].size()-x!=t[i][2].size()-y) return 0;
	while(x<=t[i][1].size())
	{
		if(t[i][1][x]!=t[i][2][y]) return 0;
		++x,++y;
	}
	return 1;
}

int ans=0;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
	{
		cin>>s[i][1]>>s[i][2];
		tos[i][1]=++cnts;
		tos[i][2]=++cnts;
		int ss1=tos[i][1],ss2=tos[i][2];
		for(int j=0;j<s[i][1].size();++j)
		{
			if(j==0) sums[ss1].pb(s[i][1][j]);
			else sums[ss1].pb(sums[ss1][j-1]*B+s[i][1][j]);
		}
		for(int j=0;j<s[i][2].size();++j)
		{
			if(j==0) sums[ss2].pb(s[i][2][j]);
			else sums[ss2].pb(sums[ss2][j-1]*B+s[i][2][j]);
		}
	}
	
	for(int i=1;i<=q;++i)
	{
		cin>>t[i][1]>>t[i][2];
		tot[i][1]=++cntt;
		tot[i][2]=++cntt;
		int ss1=tot[i][1],ss2=tot[i][2];
		for(int j=0;j<t[i][1].size();++j)
		{
			if(j==0) sumt[ss1].pb(t[i][1][j]);
			else sumt[ss1].pb(sumt[ss1][j-1]*B+t[i][1][j]);
		}
		for(int j=0;j<t[i][2].size();++j)
		{
			if(j==0) sumt[ss2].pb(t[i][2][j]);
			else sumt[ss2].pb(sumt[ss2][j-1]*B+t[i][2][j]);
		}
	}
	
	
	for(int i=1;i<=q;++i)
	{
		for(int j=1;j<=n;++j)
		{
			int z=0;
			for(int k=0;k<t[i][1].size();++k)
			{
				if(z==1) break;
				if(z==0)
				{
					
					if(sumt[tot[i][1]][k+s[j][1].size()-1]-sumt[tot[i][1]][k-1]==sums[tos[i][1]][s[j][1].size()]*mypow(B,k)
						&& sumt[tot[i][2]][k+s[j][2].size()-1]-sumt[tot[i][2]][k-1]==sums[tos[i][2]][s[j][2].size()]*mypow(B,k)
						&& ck(i,k+s[j][1].size(),k+s[j][2].size())==1)
					{
						++ans;
					}
				}
				if(t[i][1][k]!=t[i][2][k]) z=1;
			}
		}
	}
	
	printf("%d",ans);
	
	return 0;
}
