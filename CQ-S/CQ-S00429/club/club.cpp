#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define lxl long long
#define INF 1000000000
namespace lzz
{
	int T,n,ans,b[N],ct;
	int t[4],is[N],a[N][4];
	void clr(){t[0]=t[1]=t[2]=ans=0;}
	int main()
	{
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		cin>>T;
		while(T--)
		{
			clr(),cin>>n;
			for(int i=1;i<=n;i++)
			{
				int mx=-1,pos=-1;
				for(int j=0;j<3;j++)
				{
					cin>>a[i][j];
					if(mx<a[i][j])mx=a[i][j],pos=j;
				}ans+=mx,t[pos]++,is[i]=pos;
			}int nd=-1; if(t[0]>=n/2)nd=0; if(t[1]>=n/2)nd=1; if(t[2]>=n/2)nd=2;
			if(nd!=-1)
			{
				ct=0;
				for(int i=1;i<=n;i++)
				{
					if(is[i]!=nd)continue;
					int mx=-1; for(int j=0;j<3;j++)if(nd^j)mx=max(mx,a[i][j]);
					b[++ct]=a[i][nd]-mx;
				}sort(b+1,b+ct+1); for(int i=1;i<=t[nd]-n/2;i++)ans-=b[i];
			}cout<<ans<<'\n';
		}
		
		return 0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	return lzz::main();
}
