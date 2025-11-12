#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
using namespace std;

#define rk asdfiopuasiodfuioauf

const int N=100005;
int T,n;
int a[N][3],rk[N][3];
vector<int>p[3];

//注意是从0开始编号 

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			rk[i][0]=0,rk[i][1]=1,rk[i][2]=2;
			for(int j=0;j<3;j++)
				for(int k=j+1;k<3;k++)
					if(a[i][rk[i][j]]<a[i][rk[i][k]]) swap(rk[i][j],rk[i][k]);
//			printf("%d %d %d\n",rk[i][0],rk[i][1],rk[i][2]);
		}
		p[0].clear();
		p[1].clear();
		p[2].clear();
		
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i][rk[i][0]];
			p[rk[i][0]].pb(a[i][rk[i][0]]-a[i][rk[i][1]]);
		}
		
		for(int i=0;i<3;i++)
			if((int)p[i].size()>n/2)
			{
				sort(p[i].begin(),p[i].end(),[](int x,int y){
					return x>y;
				});
				for(int j=n/2;j<(int)p[i].size();j++)
					ans-=p[i][j];
			}
		
		printf("%lld\n",ans);
	}
	return 0;
}

