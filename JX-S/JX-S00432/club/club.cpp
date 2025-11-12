#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int q,n,a[100005][4],b[100005],cnt[4],ans;
inline void add(int x,int y,int z)
{
	int ma=max({x,y,z}),p=0;
	if(ma==x)
		p=1;
	if(ma==y)
	{
		if(p!=0)
			return;
		p=2;
	}
	if(ma==z)
	{
		if(p!=0)
			return;
		p=3;
	}
	cnt[p]++;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>q;
	while(q--)
	{
		cin>>n,cnt[1]=cnt[2]=cnt[3]=ans=0;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3],add(a[i][1],a[i][2],a[i][3]);
		for(int i=1;i<=n;i++)
			ans+=max({a[i][1],a[i][2],a[i][3]});
		int ma=0,p=0;
		for(int i=1;i<=3;i++)
			if(cnt[i]>ma)
				ma=cnt[i],p=i;
		if(ma<=n/2)
		{
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			int ma1=0;
			for(int j=1;j<=3;j++)
				if(j!=p)
					ma1=max(ma1,a[i][j]);
			if(a[i][p]<=ma1)
				b[i]=1e18;
			else b[i]=a[i][p]-ma1;
		}
		sort(b+1,b+n+1);
		for(int i=1;i<=ma-n/2;i++)
			ans-=b[i];
		cout<<ans<<endl;
	}
	return 0;
}
