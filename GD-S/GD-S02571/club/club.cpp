#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][3],zd,w,r[3],an,d[100005][3],cnt[3];
void up(int x,int y)
{
	if(x==1)return ;
	if(d[x][y]>d[x/2][y])swap(d[x][y],d[x/2][y]),up(x/2,y);
}
void down(int x,int y)
{
	if(x*2>cnt[y])return ;
	if(x*2+1>cnt[y]||d[x*2][y]>d[x*2+1][y])
	{
		if(d[x*2][y]>d[x][y])swap(d[x*2][y],d[x][y]),down(x*2,y);
	}
	else
	{
		if(d[x*2+1][y]>d[x][y])swap(d[x*2+1][y],d[x][y]),down(x*2+1,y);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		r[0]=r[1]=r[2]=cnt[0]=cnt[1]=cnt[2]=an=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		for(int i=1;i<=n;i++)
		{
			zd=-1;
			if(r[0]<n/2){if(a[i][0]>zd)zd=a[i][0],w=0;}
			else if(a[i][0]+d[1][0]>zd)zd=a[i][0]+d[1][0],w=0;
			if(r[1]<n/2){if(a[i][1]>zd)zd=a[i][1],w=1;}
			else if(a[i][1]+d[1][1]>zd)zd=a[i][1]+d[1][1],w=1;
			if(r[2]<n/2){if(a[i][2]>zd)zd=a[i][2],w=2;}
			else if(a[i][2]+d[1][2]>zd)zd=a[i][2]+d[1][2],w=2;
			an+=zd;
			if(r[w]==n/2)
			{
				d[1][w]=d[cnt[w]][w];
				cnt[w]--;
				r[w]--;
				down(1,w);
			}
			if(w==0)d[++cnt[0]][0]=max(a[i][1],a[i][2])-a[i][0];
			else if(w==1)d[++cnt[1]][1]=max(a[i][0],a[i][2])-a[i][1];
			else d[++cnt[2]][2]=max(a[i][0],a[i][1])-a[i][2];
			up(cnt[w],w);
			r[w]++;
//			cout<<i<<' '<<an<<' '<<w<<' '<<d[1][1]<<'\n';
		}
//		cout<<r[0]<<' '<<r[1]<<' '<<r[2]<<'\n';
		cout<<an<<'\n';
	}
	return 0;
}
