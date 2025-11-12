#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+5;
int T,n,a[N][4],mmax=-0x7fffffff,wu[N]={0};
void dfs(int step=1)
{
	if(step==n+1)
	{
		int cnta,cntb,cntc,pa,pb,pc;
		cnta=cntb=cntc=pa=pb=pc=0;
		for(int i=1;i<=n;i++)
		{
			if(wu[i]==1)
			{
				cnta++;
				pa+=a[i][1];
			}else if(wu[i]==2)
			{
				cntb++;
				pb+=a[i][2];
			}else
			{
				cntc++;
				pc+=a[i][3];
			}
		}
		int hi=n/2;
		if(cnta>hi || cntb>hi || cntc>hi)
		{
			return;
		}
		mmax=max(mmax,pa+pb+pc);
		return;
	}
	wu[step]=1;
	dfs(step+1);
	wu[step]=2;
	dfs(step+1);
	wu[step]=3;
	dfs(step+1);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	dfs();
	cout<<mmax<<'\n';
	mmax=-0x7fffffff;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
		solve();
	return 0;
}
