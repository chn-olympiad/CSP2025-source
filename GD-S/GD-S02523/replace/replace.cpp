#include<bits/stdc++.h>
#define ll long long
#define up(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=2e5+10;
int n,m;
string a[N],b[N],s[N],t[N],c[N],d[N];
map<string,map<string,int> > g; 
int main()
{
	freopen("replace.in","r",stdin);	
	freopen("replace.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	up(i,1,n)cin>>a[i]>>b[i];
	up(i,1,m)cin>>s[i]>>t[i];
	up(i,1,n)
	{
		int x=0;
		int len=a[i].size()-1;
		up(j,0,len)
		{
			if(a[i][j]!=b[i][j])
			{
				x=1;
				c[i]+=a[i][j];
				d[i]+=b[i][j];
			}
			else
			{
				if(x)break;
			}
		}
		g[c[i]][d[i]]++;
	}
	up(i,1,m)
	{
		string sa,sb;
		int len=s[i].size()-1,x=0,p=0,noo=0;
		up(j,0,len)
		{
			if(s[i][j]!=t[i][j])
			{
				x=1;
			}
			if(x)
			{
				sa+=s[i][j];
				sb+=t[i][j];
			}
		}
		while(sa[sa.size()-1]==sb[sa.size()-1])sa.erase(sa.size()-1),sb.erase(sb.size()-1);
		if(noo)cout<<"0\n";
		else cout<<g[sa][sb]<<'\n';
	}
	return 0;
} 
