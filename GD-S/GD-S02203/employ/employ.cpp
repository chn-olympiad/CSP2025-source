#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
const int Mod=998244353;
int n,m;
string s;
int c[N];
int f[N][19];
inline void add(int &x,int y)
{
	int res=x+y;
	x=(res>=Mod?res-Mod:res);
}
int lim[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)
		cin>>c[i];
	f[0][0]=1;
	for(int S=0;S<(1<<n);S++)
	{
		int x=S,dy=0;
		while(x) dy+=(x&1),x>>=1;
		for(int i=0;i<=dy;i++)
		{
			int fq=dy-i;
			for(int j=0;j<n;j++)
			{
				if((S>>j)&1)continue;
				add(f[S^(1<<j)][i+((c[j]>fq)&&(s[dy]=='1'))],f[S][i]);
			}
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++)
		add(ans,f[(1<<n)-1][i]);
	cout<<ans;
	return 0;
}
