#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int n,T,b[4],ans;
struct edge
{
	int id,res;
}a[200001][3];
struct node
{
	int id,res,pos;
	inline bool operator<(const node &x) const{
		return res>x.res;
	}
};
inline bool cmp(edge a1,edge a2)
{
	return a1.res>a2.res;
}
priority_queue<node>q[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		ans=0;
		for(int i=1;i<=3;i++)
			while(!q[i].empty()) q[i].pop();
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1].res>>a[i][2].res>>a[i][3].res;
			a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
			sort(a[i]+1,a[i]+4,cmp);
		}
		for(int i=1;i<=n;i++)
		{
			int l1=a[i][1].id,l2=a[i][2].id;
			if(b[l1]<n/2)
			{
				b[l1]++,ans+=a[i][1].res;
				q[l1].push((node){i,a[i][1].res-a[i][2].res,1});
				continue;
			}
			else
			{
				node u=q[l1].top();
				if(u.res>a[i][1].res-a[i][2].res)
					q[l2].push((node){i,a[i][2].res-a[i][3].res,2}),ans+=a[i][2].res,b[l2]++;
				else
				{
					q[l1].pop(),ans+=a[i][1].res,q[l1].push((node){i,a[i][1].res-a[i][2].res,1});
					ans-=u.res,
					q[a[u.id][u.pos+1].id].push(u),b[a[u.id][u.pos+1].id]++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
