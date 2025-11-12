#include<bits/stdc++.h>
using namespace std;
long long n,m,b[1005],a[1005],ans,qm=998244353;
bool sj[1005];
char al;
string s;
void dfs(long long rs,long long sb,long long cg)
{
	if(cg>=m)
	{
		//cout<<cg<<' '<<ans<<endl;
		long long aa=1;
		for(int i=n-rs+1;i>=1;i--)
		{
			aa*=i;
			aa%=qm;
		}
		ans+=aa;
		ans%=qm;
		return ;
	}
	if(rs>=n)
	{
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1)
		{
			continue;
		}
		b[i]=1;
		if(sb>=a[i]||!sj[rs+1])
		{
//			cout<<rs<<endl;
			dfs(rs+1,sb+1,cg);
		}
		else
		{
			dfs(rs+1,sb,cg+1);
		}
		b[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	al=getchar();
	getline(cin,s);
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='0')
		{
			sj[i]=false;
		}
		else
		{
			sj[i]=true;
		}
//		cout<<sj[i]<<endl;
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
