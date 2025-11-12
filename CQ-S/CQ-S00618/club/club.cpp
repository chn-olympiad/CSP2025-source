#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int T,n,m,ans,a[N][4],b[N],b_[N],c[4],v[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		ans=0;
		memset(c,0,sizeof(c));
		m=0;
		for(int i=1;i<=n;i++)
		{
			b[i]=b_[i]=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>=a[i][b[i]])	b[i]=j;
			}
			for(int j=1;j<=3;j++)
				if(j!=b[i]&&a[i][j]>=a[i][b_[i]])
					b_[i]=j;
			c[b[i]]++;
			ans+=a[i][b[i]];
		}
		for(int i=1;i<=3;i++)
			if(c[i]>n/2)
			{
				for(int j=1;j<=n;j++)
					if(b[j]==i)
						v[++m]=a[j][b[j]]-a[j][b_[j]];
				sort(v+1,v+m+1);
				for(int j=1;j<=c[i]-n/2;j++)	ans-=v[j];
			}
		cout<<ans<<'\n';
	}
	return 0;
}
