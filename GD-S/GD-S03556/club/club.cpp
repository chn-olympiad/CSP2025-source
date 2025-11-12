#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{ int like,id; };
bool cmp(node x,node y)
{
	return x.like>y.like ;
}
struct mem{
	node d[5];
}a[100005];
int T,n,ans;
vector<int> vec[5];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		for(int i=1;i<=3;i++)vec[i].clear();
		cin>>n;ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].d[1].like,&a[i].d[2].like,&a[i].d[3].like);
			a[i].d[1].id=1;a[i].d[2].id=2;a[i].d[3].id=3;
			sort(a[i].d+1,a[i].d+4,cmp);
			ans+=a[i].d[1].like;
			vec[a[i].d[1].id].push_back(a[i].d[1].like-a[i].d[2].like);
		}
		for(int ch=1;ch<=3;ch++)
		{
			int len=vec[ch].size();
			if(len>n/2)
			{
				sort(vec[ch].begin(),vec[ch].end());
				for(int j=0;j<len-n/2;j++)
					ans-=vec[ch][j];
				break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
