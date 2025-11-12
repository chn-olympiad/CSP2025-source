#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=5e2+5;
const int mod=998244353;
const int INF=0x3f3f3f3f;
const LL LINF=0x3f3f3f3f3f3f3f3f;
int n,m,c[N],p[N],vis[N];
LL fac[N],ans;
string s;
bool ch()
{
	int r=0,u=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='0'||u>=c[p[i]])
			u++;
		else
			r++;
	return r>=m;
}
void dfs(int k)
{
	if(k>n)
	{
		ans+=ch();
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			p[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//	freopen("employ1.in","r",stdin);
//	freopen("employ1.out","w",stdout);
//	freopen("empoy.in","r",stdin);
//	freopen("empoy.out","w",stdout);
//	fropen("employ.in","r",stdin);
//	fropen("employ.out","w",stdout);
//	freopen("employ.out","r",stdin);
//	freopen("employ.in","w",stdout);
//	freopen("employ.in","w",stdin);
//	freopen("employ.out","r",stdout);
//	freopen("employ.in","r",stdout);
//	freopen("employ.out","w",stdin);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	fac[0]=1;
	int ff=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		fac[i]=fac[i-1]*i%mod;
		ff+=s[i]-'0';
	}
	if(ff<m)
	{
		cout<<0;
		return 0;
	}
	sort(c+1,c+n+1);
	if(m==n)
	{
		if(ff==n&&c[1])
			cout<<fac[n];
		else
			cout<<0;
		return 0;
	}
	if(n<=11)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	cout<<0;
//	cout<<"wan an";
//	cout<<"guo yu kun nan xwx";
//	cout<<"zhu bo wo xi huan ni";
//	cout<<"guan zhu luogu 555301 xie xie miao";
	return 0;
}
//meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow meow
