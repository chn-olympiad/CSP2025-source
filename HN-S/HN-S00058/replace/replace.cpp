#include<bits/stdc++.h>
#define rep(i,l,r,k) for(int i=l;i<=r;i+=k)
#define rrep(i,r,l,k) for(int i=r;i>=l;i-=k)
#define loop(i,st,ed,nxt) for(int i=st;i!=ed;i=nxt)
#define int long long
#define ull unsigned long long
using namespace std;
const int N=2e5+5,M=5e6+5;
string s1[N],s2[N];
ull h1[N],h2[N];
ull ha[2][M],pw[M];
ull qry(ull *aaa,int l,int r)
{return aaa[r]-aaa[l-1]*pw[r-l+1];}
void init()
{
	
}
void solve()
{
	int n,m;
	cin>>n>>m;
	pw[0]=1;
	rep(i,1,M-1,1)pw[i]=pw[i-1]*131;
	rep(i,1,n,1)
	{
		cin>>s1[i]>>s2[i];
		int l=s1[i].size();
		rep(j,0,l-1,1)h1[i]=h1[i]*131+s1[i][j],
			h2[i]=h2[i]*131+s2[i][j];
	}
	rep(i,1,m,1)
	{
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<"0\n";
			continue;
		}
		int len=t1.size(),ans=0,fr=-1,lst=-1;
		t1="#"+t1,t2="#"+t2;
		rep(j,1,len,1)
		{
			ha[0][j]=ha[0][j-1]*131+t1[j];
			ha[1][j]=ha[1][j-1]*131+t2[j];
			if(t1[j]!=t2[j])lst=j;
		}
		rrep(j,len,1,1)if(t1[j]!=t2[j])fr=j;
		rep(k,1,n,1)rep(j,1,fr,1)
		{
			int l=s1[k].size();
			if(j+l-1<=len&&qry(ha[0],j,j+l-1)==h1[k]&&
			   qry(ha[1],j,j+l-1)==h2[k]&&j+l-1>=lst)
				++ans;
		}
		cout<<ans<<'\n';
	} 
}
signed main()
{
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	//cin>>T;
	init();
	rep(i,1,T,1)
	{
		solve();
	}
	return 0;
}


