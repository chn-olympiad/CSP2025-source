#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,ans;
int a[N][4],b[4][N],cnt[4];
int calcmx(int x,int y,int z){return max(x,max(y,z));}
int calcmt(int x,int y,int z)
{
	if(x>=min(y,z)&&x<=max(y,z)) return x;
	if(y>=min(x,z)&&y<=max(x,z)) return y;
	return z;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n),ans=0;
		for(int i=1;i<=3;i++) cnt[i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) scanf("%d",&a[i][j]);
			int mx=calcmx(a[i][1],a[i][2],a[i][3]),mt=calcmt(a[i][1],a[i][2],a[i][3]); ans+=mx;
			for(int j=1;j<=3;j++) if(mx==a[i][j]){b[j][++cnt[j]]=mx-mt; break;}
		}
		for(int i=1;i<=3;i++)
		{
			if(cnt[i]>n/2)
			{
				sort(b[i]+1,b[i]+1+cnt[i]);
				for(int j=1;j<=cnt[i]-n/2;j++) ans-=b[i][j];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
