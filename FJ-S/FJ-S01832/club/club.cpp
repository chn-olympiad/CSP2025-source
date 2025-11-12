#include<bits/stdc++.h>
using namespace std;
const int N=1e4+9;
int T,n,a[N],ge[4],ans,xuan[N],e[4];
struct node
{
	int z,id;
	bool operator<(const node a)
	{
		return z<a.z;
	}
}gai[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<3;i++)ge[i]=0;ans=0;
		for(int e1,e2,e3,i=1;i<=n;i++)
		{
			int maxx=-1;
			for(int j=1;j<=3;j++)
			{
				cin>>e[j];
				if(maxx<e[j])maxx=e[j],xuan[i]=j;
			}
			sort(e+1,e+1+3);
			ge[xuan[i]]++;
			ans+=e[3];gai[i].z=e[3]-e[2];gai[i].id=i;
//			cout<<e1<<' '<<gai[i].z<<' '<<xuan[i]<<"???\n";
		}
		sort(gai+1,gai+1+n);
		for(int i=1;i<=3;i++)
		{
			if(ge[i]>n/2)
			{
				for(int j=1;j<=n;j++)
				{
					if(xuan[gai[j].id]==i)
					{
						ge[i]--;
						ans-=gai[j].z;
						if(ge[i]==n/2)break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
