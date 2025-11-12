#include<bits/stdc++.h>		//Ren5Jie4Di4Ling5%
using namespace std;
int t,n,a[100005][5],ans;
void find(int x,int y,int aa,int b,int c,int s)
{
//	cout<<x<<" "<<y<<" "<<ans<<'\n';
	s+=a[x][y];
	ans=max(ans,s);
	if(x==0) return;
	if(aa+1<=n/2)
		find(x-1,1,aa+1,b,c,s);
	if(b+1<=n/2)
		find(x-1,2,aa,b+1,c,s);
	if(c+1<=n/2)
		find(x-1,3,aa,b,c+1,s);
}
int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		ans=0;
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
			scanf("%d%d%d",&a[j][1],&a[j][2],&a[j][3]);
		find(n,1,1,0,0,0);
//		cout<<'\n';
		find(n,2,0,1,0,0);
//		cout<<'\n';
		find(n,3,0,0,1,0);
		printf("%d\n",ans);
	}
	return 0;
}
/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e5+5;
int t,n,a[4][MAXN];
struct club{
	int w,i;
}cl[4][MAXN];
ll ans;
bool all[MAXN];
bool cmp(club x,club y)
{
	return x.w>y.w;
}
bool f[4][MAXN];
int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		ans=0;
		memset(all,0,sizeof(all));
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			scanf("%d%d%d",&a[1][j],&a[2][j],&a[3][j]);
			cl[1][j].w=a[1][j];
			cl[2][j].w=a[2][j];
			cl[3][j].w=a[3][j];
			cl[1][j].i=cl[2][j].i=cl[3][j].i=j;
		}
		sort(cl[1]+1,cl[1]+n+1,cmp);
		sort(cl[2]+1,cl[2]+n+1,cmp);
		sort(cl[3]+1,cl[3]+n+1,cmp);
		for(int j=n/2+1;j<=n;j++)
		{
			f[1][cl[1][j].i]=1;
			f[2][cl[2][j].i]=1;
			f[2][cl[3][j].i]=1;
		}
		for(int k=1;k<=3;k++)
		{
			/*for(int j=1;j<=n;j++)
				cout<<cl[k][j].w<<' ';
			cout<<'\n';*/
			for(int j=1;j<=n/2;j++)
			{
				int x=0,y=0;
				if(k==1) x=2,y=3;
				if(k==2) x=1,y=3;
				if(k==3) x=1,y=2;
				if(all[j]==1)
					continue;
				int u=cl[k][j].i;
				if(a[k][u]>a[x][u]&&a[k][u]>a[y][u]){
					ans+=a[k][u];
					all[u]=1;
					continue;
				}
				if(a[k][u]<a[x][u]&&a[k][u]>a[y][u]){
					if(f[x][u]==1){
						ans+=a[k][u];
						all[u]=1;
						continue;
					}
				}
				if(a[k][u]<a[y][u]&&a[k][u]>a[x][u]){
					if(f[y][j]==1){
						ans+=a[k][u];
						all[u]=1;
						continue;
					}
				}
				if(a[k][u]<a[x][u]&&a[k][u]<a[y][u]){
					if(f[x][j]==1&&f[y][j]==1){
						ans+=a[k][u];
						all[u]=1;
						continue;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}*/
