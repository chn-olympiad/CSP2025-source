#include<bits/stdc++.h>
#define fin(x) freopen(#x".in","r",stdin)
#define fout(x) freopen(#x".out","w",stdout)
#define fans(x) freopen(#x".ans","w",stdout)
const int N=1e5+7;
using namespace std;
int n,q;
namespace Solve2
{
	struct Node{int l,r;}a[N],b[N],qry1[N],qry2[N];
	vector<pair<int,int>>ve[N*100];
	vector<array<int,3>>qr[N*100];
	int in[N],tot,ans[N];
	struct Bits
	{
		int s[N*100],n,clr[N*100],tot,vis[N*100];
		int low_bit(int x){return x&(-x);}
		void init(int k)
		{
			n=k;
			for(int i = 1;i<= tot;i++)
			{
				s[clr[i]]=0,vis[clr[i]]=1;
			}
			tot=0;
		}
		void add(int x,int v)
		{
			if(x==0)
			{
				s[0]+=v;
				if(!vis[0])clr[++tot]=0,vis[0]=1;
				return;
			}
			while(x<=n)
			{
				if(!vis[x])clr[++tot]=x,vis[x]=1;
				s[x]+=v;
				x+=low_bit(x);
			}
		}
		int ask(int x)
		{
			int ans=s[0];
			while(x)
			{
				ans+=s[x];
				x-=low_bit(x);
			}
			return ans;
		}
	}bts;
	void solve()
	{
		for(int i = 1;i<= n;i++)
		{
			string s;
			cin>>s;
			for(int j = 0;j<(int)s.size();j++)
				if(s[j]=='b')
				{
					a[i]={j,(int)s.size()-j-1};
					break;
				}
			cin>>s;
			for(int j = 0;j<(int)s.size();j++)
				if(s[j]=='b')
				{
					b[i]={j,(int)s.size()-j-1};
					break;
				}
			ve[b[i].l-a[i].l+N*50].emplace_back(a[i].l,a[i].r);
		}
		for(int i = 1;i<= q;i++)
		{
			string s;
			cin>>s;
			for(int j = 0;j<(int)s.size();j++)
				if(s[j]=='b')
				{
					qry1[i]={j,(int)s.size()-j-1};
					break;
				}
			cin>>s;
			for(int j = 0;j<(int)s.size();j++)
				if(s[j]=='b')
				{
					qry2[i]={j,(int)s.size()-j-1};
					break;
				}
			qr[qry2[i].l-qry1[i].l+N*50].push_back(array<int,3>{qry1[i].l,qry1[i].r,i});
			in[++tot]=qry2[i].l-qry1[i].l+N*50;
		}
		sort(in+1,in+tot+1);
		tot=unique(in+1,in+tot+1)-in-1;
		for(int g=1;g<= tot;g++)
		{
			int k=in[g];
			bts.init(N*100);
			sort(qr[k].begin(),qr[k].end());
			sort(ve[k].begin(),ve[k].end());
			int nw=0,m=ve[k].size();
			for(int i = 0;i< (int)qr[k].size();i++)
			{
				int l=qr[k][i][0],r=qr[k][i][1],nu=qr[k][i][2];
				while(nw<m&&l>=ve[k][nw].first)
					bts.add(ve[k][nw].second,1),nw++;
				ans[nu]=bts.ask(r);
			}
		}
		for(int i = 1;i<= q;i++)cout<<ans[i]<<'\n';
	}
}
int main()
{
//	fin(replace),fout(replace);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	Solve2::solve();
}
