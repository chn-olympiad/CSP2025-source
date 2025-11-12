#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int T,n,a[N][5],b[N],mp[N],m[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int ma[5]={0,0,0,0,0},pos=0,num=0;
		ll ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			int maxn=max({a[i][1],a[i][2],a[i][3]});
			ans+=ll(maxn);
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]==maxn)
				{
					m[i]=maxn;
					mp[i]=j;
					ma[j]++;
					break;
				}
			}
		}
		if(ma[1]>n/2)pos=1;
		if(ma[2]>n/2)pos=2;
		if(ma[3]>n/2)pos=3;
		if(pos)
		{
			for(int i=1;i<=n;i++)
			{
				if(mp[i]==pos)
				{
					int p[5],cnt=0;
					for(int j=1;j<=3;j++)
					{
						if(j==pos)continue;
						p[++cnt]=a[i][j];
					}
					b[++num]=min(m[i]-p[1],m[i]-p[2]);
				}
			}
			sort(b+1,b+ma[pos]+1);
//			for(int i=1;i<=ma[pos];i++)cout<<b[i]<<" ";
			for(int i=1;i<=ma[pos]-n/2;i++)ans-=b[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
