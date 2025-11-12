#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<string>
#include<bitset>
#include<cstring>
#include<numeric>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e5+10;
const int N=1e5;
const int INF=0x3f3f3f3f;
const long long LINF=0x3f3f3f3f3f3f3f3f;
int n;
long long ans=0;
int a[MAXN][3];
int p[MAXN];
inline void solve(){
	scanf("%d",&n);
	ans=0;
	int c[3]={0,0,0};
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		p[i]=max_element(a[i],a[i]+3)-a[i];
		c[p[i]]++;
		ans+=a[i][p[i]];
	}
	int x=3;
	for(int i:{0,1,2})
	{
		if(c[i]>(n>>1)){
			x=i;
		}
	}
	vector <int> ext;
	for(int i=1;i<=n;i++)
	{
		if(p[i]==x){
			int cur=0;
			for(int j:{0,1,2})
			{
				if(j^p[i]){
					cur=max(cur,a[i][j]);
				}
			}
			ext.push_back(a[i][p[i]]-cur);
		}
	}
	if(x<3){
		sort(ext.begin(),ext.end());
		for(int i=0;i<c[x]-(n>>1);i++)
		{
			ans-=ext[i];
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	#ifdef LOCAL
	atexit([](){fprintf(stderr,"%.3lfs\n",(double)clock()/CLOCKS_PER_SEC);});
	#endif
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}