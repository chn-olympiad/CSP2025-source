#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10,mod=998244353;
int n,m,c[N],ans,vis[N];
string s;
int A(int a)
{
	int sum=1;
	while(a) sum=(sum*a)%mod,a--;
}
int dfs(int now,int alr,int killed)
{
	if(alr==n) return 1;
	if(killed>=c[now-1]) return 0;
	int re=0;
	if(s[alr]=='0') killed++;
	for(int i=1;i<=n;i++)
		if(!vis[i]) vis[i]=1,re+=dfs(i,alr+1,killed),vis[i]=0;
	return re;
}
bool pd()
{
	for(int i=1;i<=n;i++)
		if(c[i-1]==0) return true;
	return false;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i-1];
	if(pd())
	{
		cout<<"0"<<endl;
		return 0;
	}
	else cout<<A(n);
	return 0;
}
