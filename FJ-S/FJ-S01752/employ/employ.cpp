#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=20,K=(1<<18),MOD=998244353,inf=0x3f3f3f3f;
bool a[N];int c[N],n,m,f[N][N][K];
ll dfs(int x,int r,int b)
{
//	cout<<x<<" "<<r<<endl;
	int e=0;
	if(f[x][r][b]!=-1) return f[x][r][b];
	if(x==n+1) return r>=m;
	for(int i=1;i<=n;i++)
		if(!(b&(1<<(i-1))))
		{
			int ww=b;b|=(1<<(i-1));
			if(c[i]>x-1-r && a[x]) e=(e+dfs(x+1,r+1,b))%MOD;
			else e=(e+dfs(x+1,r,b))%MOD;
			b=ww;
		}
	f[x][r][b]=e;return e;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int rr=1;cin>>n>>m;memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		char op;cin>>op;a[i]=(op-'0');
		if(!a[i]) rr=0;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18) {cout<<dfs(1,0,0);return 0;}
	puts("0");
	return 0;
}
