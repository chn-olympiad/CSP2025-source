#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define int long long
#define mkp(a,b,c) make_pair((int)(a),make_pair((int)(b),(int)(c)))
using namespace std;
const int N=100020;
struct _{
	int x,id;
}a[N][4];
int n;
priority_queue<pair<int,pair<int,int> > > q[4];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		fo(i,1,3)while(!q[i].empty())q[i].pop();
		scanf("%lld",&n);
		fo(i,1,n)fo(j,1,3)scanf("%lld",&a[i][j].x),a[i][j].id=j;
		fo(i,1,n)sort(a[i]+1,a[i]+4,[](_ x,_ y){return x.x<y.x;});
		int ans=0;
		fo(i,1,n)
			ans+=a[i][3].x,
			q[a[i][3].id].push(mkp(a[i][2].x-a[i][3].x,3,i));
		fo(t,1,5)
			fo(i,1,3)
				while(!q[i].empty()&&(int)q[i].size()>n/2)
				{
					int y=q[i].top().second.first,x=q[i].top().second.second,z=q[i].top().first;
					q[i].pop();
					ans+=z;
					q[a[x][y-1].id].push(mkp((y!=1?a[x][y-2].x-a[x][y-1].x:INT_MIN),y-1,x));
				}
		printf("%lld\n",ans);
	}	
	return 0;
}
