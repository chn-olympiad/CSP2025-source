#include<bits/stdc++.h>
using namespace std;

int T,n,a[100010][3],p[100010][3],b[100010],sz[3];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)
	{
		sz[0]=sz[1]=sz[2]=0;
		cin>>n;
		int sumx=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int maxn=max({a[i][0],a[i][1],a[i][2]});
			if(maxn==a[i][0]) p[++sz[0]][0]=i;
			else if(maxn==a[i][1]) p[++sz[1]][1]=i;
			else p[++sz[2]][2]=i;
			sumx+=maxn;
		}
		if(sz[0]<=n/2 && sz[1]<=n/2 && sz[2]<=n/2)
		{
			cout<<sumx<<endl;
			continue;
		}
		if(sz[0]>n/2)
		{
			for(int i=1;i<=sz[0];i++)
				b[i]=a[p[i][0]][0]-max(a[p[i][0]][1],a[p[i][0]][2]);
			sort(b+1,b+sz[0]+1);
			for(int i=1;i<=sz[0]-(n/2);i++) sumx-=b[i];
		}
		if(sz[1]>n/2)
		{
			for(int i=1;i<=sz[1];i++)
				b[i]=a[p[i][1]][1]-max(a[p[i][1]][2],a[p[i][1]][0]);
			for(int i=1;i<=sz[1]-(n/2);i++) sumx-=b[i];
		}
		if(sz[2]>n/2)
		{
			for(int i=1;i<=sz[2];i++)
				b[i]=a[p[i][2]][2]-max(a[p[i][2]][0],a[p[i][2]][1]);
			for(int i=1;i<=sz[2]-(n/2);i++) sumx-=b[i];
		}
		cout<<sumx<<endl;
	}
	return 0;
}
