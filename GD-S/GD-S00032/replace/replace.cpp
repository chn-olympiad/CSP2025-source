#include<bits/stdc++.h>
using ull=unsigned long long;
using namespace std;
const ull base=1009071;
const int N=2e5+5;
const int M=2.5e6+6;
int n,q;
string s[N][2];
vector<int>diff[N];
// vector<int>hav[N];
map<int,vector<int>>hav[N][27];
ull sum[N][2],t_sum[2][N],p[M]{1};
constexpr void init()
{
	for(int i=1;i<M;i++)p[i]=p[i-1]*base;
}
inline ull get(int op,int l,int r)
{
	return t_sum[op][r]-t_sum[op][l-1]*p[r-l+1];
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		ull s1=0,s2=0;
		diff[i].clear();
		cin>>s[i][0]>>s[i][1];
		int m=s[i][0].size(),cnt,lst=0;
		for(int j=0;j<m;j++)
		{
			s1=s1*base+s[i][0][j]-'a';
			s2=s2*base+s[i][1][j]-'a';
			if(s[i][0][j]!=s[i][1][j])
			{
				diff[i].push_back(j-lst);
				lst=j;
			}
		}
		sum[i][0]=s1,sum[i][1]=s2;
		if(diff[i].size())
		hav[diff[i].size()][s[i][0][diff[i][0]]][lst-diff[i][0]].push_back(i);
	}
	for(int _=1;_<=q;_++)
	{
		string t[2];
		cin>>t[0]>>t[1];
		int m=t[0].size(),cnt=0,lst=0;
		vector<int>now_diff;
		ull s1=0,s2=0;
		for(int i=0;i<m;i++)
		{
			s1=s1*base+t[0][i]-'a';
			s2=s2*base+t[1][i]-'a';
			if(t[0][i]!=t[1][i])
			{
				now_diff.push_back(i-lst);
				lst=i;
				cnt++;
			}
			t_sum[0][i]=s1;
			t_sum[1][i]=s2;
		}
		int ans=0;
		auto now=hav[cnt][t[0][now_diff[0]]][lst-now_diff[0]];
		for(auto x:now)
		{
			int a=now_diff[0],b=diff[x][0];
			if(a<b)continue;
			int l=a-b;
			if(l+s[x][0].size()-1<lst)continue;
			if(l+s[x][0].size()-1>=m)continue;
			if(get(0,l,l+s[x][0].size()-1)==sum[x][0]&&get(1,l,l+s[x][1].size()-1)==sum[x][1])
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}
