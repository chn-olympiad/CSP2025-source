#include<bits/stdc++.h>
#define int long long
using namespace std;
int m[100010][4];
int v[4][100010];
int a1[100010][4],cc[100010],T,tt[4];
struct N{
	int b;
	int id;
	int wh;
}ll[100010];
int cmp(N x,N y)
{
	return x.b>y.b;
}
int cmp2(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		memset(tt,0,sizeof(tt));
		for(int i=1;i<=n;i++) ll[i].b=-1e15;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>m[i][1]>>m[i][2]>>m[i][3];
		for(int i=1;i<=n;i++)
		{
			int maxx=max(max(m[i][1],m[i][2]),m[i][3]);
			ans+=maxx;
			if(maxx==m[i][1]) v[1][++tt[1]]=i;
			else if(maxx==m[i][2]) v[2][++tt[2]]=i;
			else v[3][++tt[3]]=i;
		}
		int k=0;
		for(int i=1;i<=3;i++) if(tt[i]>n/2) k=i;
		if(!k)
		{
			cout<<ans<<endl;
			continue;
		}
		int len=tt[k];
		for(int i=1;i<=len;i++)
		{
			ll[i].id=i;
			for(int j=1;j<=3;j++)
			{
				if(j==k) continue;
				a1[i][j]=m[v[k][i]][j]-m[v[k][i]][k];
				if(a1[i][j]>ll[i].b)
				{
					ll[i].b=a1[i][j];
					ll[i].wh=j;
				}
			}
		}
		sort(ll+1,ll+len+1,cmp);
		for(int i=1;i<=len-n/2;i++) 
		{
			ans+=ll[i].b;
			v[ll[i].wh][++tt[ll[i].wh]]=v[k][ll[i].id];
		}
		int kk=0;
		for(int i=1;i<=3;i++) 
		{
			if(i==k) continue;
			if(tt[i]>n/2) kk=i;
		}
		if(!kk) 
		{
			cout<<ans<<endl;
			continue;
		}
		len=tt[kk];
		for(int i=1;i<=len;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(j==k||j==kk) continue;
				cc[i]=m[v[kk][i]][j]-m[v[kk][i]][kk];
			}
 		}
 		sort(cc+1,cc+len+1);
 		for(int i=1;i<=len-n/2;i++) ans+=cc[i];
 		cout<<ans<<endl;
	}
	return 0;
} 
