#include<bits/stdc++.h>
using namespace std;
#define int long long
int tx,n,a[100005][3],ans,now,b[100005],cnt,g[3][100005],x;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>tx;
	while(tx--)
	{
		cin>>n;
		g[0][0]=g[1][0]=g[2][0]=0;
		now=-1;
		cnt=ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) g[0][++g[0][0]]=i,ans+=a[i][0];
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]) g[1][++g[1][0]]=i,ans+=a[i][1];
			else g[2][++g[2][0]]=i,ans+=a[i][2];
		}
		for(int i=0;i<3;i++) if(g[i][0]>n/2) now=i;
//		cout<<now<<endl;
		if(now==-1){
			cout<<ans<<endl;
			continue;
		}
		if(now==0) for(int i=1;i<=g[now][0];i++) x=g[now][i],b[++cnt]=a[x][0]-max(a[x][1],a[x][2]);
		else if(now==1) for(int i=1;i<=g[now][0];i++) x=g[now][i],b[++cnt]=a[x][1]-max(a[x][0],a[x][2]);
		else for(int i=1;i<=g[now][0];i++) x=g[now][i],b[++cnt]=a[x][2]-max(a[x][0],a[x][1]);
		sort(b+1,b+cnt+1);
//		for(int i=1;i<=cnt;i++) cout<<b[i]<<' ';
		for(int i=1;i<=g[now][0]-n/2;i++) ans-=b[i];
		cout<<ans<<endl;
	}
	return 0;
}
