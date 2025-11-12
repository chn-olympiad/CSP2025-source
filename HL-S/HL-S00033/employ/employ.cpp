#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=505,mod=998244353;
int n,m,c[N],ans;
bool t[N];
string s;
void dfs(int la,int k,int employ)	//mianshirenshu	employ_renshu 
{
	int e=employ;
	if(k)	if(c[la]>k-employ-1&&s[k]=='1')	e++;
//	cout<<la<<" "<<k<<" "<<e<<"\n";
	for(int i=1;i<=n;i++)
	{
		if(t[i])	continue;
		t[i]=1;
		dfs(i,k+1,e);
		t[i]=0;
	}
	if(k==n)	if(e>=m)	ans++;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	s='0'+s;
	for(int i=1;i<=n;i++)	cin>>c[i];
	c[0]=999;
	if(m==n)
	{
		for(int i=1;i<s.size();i++)
		{
			if(s[i]=='0')
			{
				cout<<"0";
				return 0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!c[i])
			{
				cout<<"0\n";
				return 0;
			}
		}
		int ans=1;
		for(int i=2;i<=n;i++)	ans=ans*i%mod;
		cout<<ans;
	}
	else
	{
		dfs(0,0,0);
		cout<<ans;
	}
	return 0;
}
//12pts
