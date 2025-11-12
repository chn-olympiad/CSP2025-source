#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=1e5+5;
const int INF=0x3f3f3f3f;
const LL LINF=0x3f3f3f3f3f3f3f3f;
int t,n,a[N][4],ans,vis[N];
struct dd
{
	int x,i,d;
	bool operator>(const dd xx)const{return x>xx.x;}
}p[N*3];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				p[(i-1)*3+j]={a[i][j],i,j};
			}
			vis[i]=0;
		}
		sort(p+1,p+n*3+1,greater<dd>());
		multiset<int>st[4];
		int ct[4]={0,0,0,0};
		ans=0;
		for(int i=1;i<=n*3;i++)
			if(!vis[p[i].i])
			{
				int mx=-1,mxx=-1;
				for(int j=1;j<=3;j++)
					if(a[p[i].i][j]>mx)
					{
						mxx=mx;
						mx=a[p[i].i][j];
					}
					else if(a[p[i].i][j]>mxx)
						mxx=a[p[i].i][j];
				if(ct[p[i].d]==n/2)
				{
					auto it=st[p[i].d].begin();
					if(p[i].x-mxx>*it)
					{
						ans-=*it;
						ans+=p[i].x;
						st[p[i].d].erase(it);
						st[p[i].d].insert(p[i].x-mxx);
					}
					else
						ans+=mxx;
				}
				else
				{
					ct[p[i].d]++;
					ans+=p[i].x;
					st[p[i].d].insert(p[i].x-mxx);
				}
				vis[p[i].i]=1;
			}
		cout<<ans<<'\n';
	}
	return 0;
}
//meow.
