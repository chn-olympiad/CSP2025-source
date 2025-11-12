#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
using ll=long long;
constexpr int N=1e5;
int T,n;
int a[N+5][3];
int c[3][N+5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int ans=0;
		fr(i,1,n)
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>max(a[i][1],a[i][2])) c[0][++c[0][0]]=i;
			else if(a[i][1]>max(a[i][0],a[i][2])) c[1][++c[1][0]]=i;
			else c[2][++c[2][0]]=i;
			ans+=max(max(a[i][0],a[i][1]),a[i][2]);
		}
		sort(c[0]+1,c[0]+1+c[0][0],[](int x,int y){return a[x][0]-max(a[x][1],a[x][2])>a[y][0]-max(a[y][1],a[y][2]);});
		sort(c[1]+1,c[1]+1+c[1][0],[](int x,int y){return a[x][1]-max(a[x][0],a[x][2])>a[y][1]-max(a[y][0],a[y][2]);});
		sort(c[2]+1,c[2]+1+c[2][0],[](int x,int y){return a[x][2]-max(a[x][0],a[x][1])>a[y][2]-max(a[y][0],a[y][1]);});
		while(c[0][0]>n/2)
		{
			ans-=a[c[0][c[0][0]]][0];
			ans+=max(a[c[0][c[0][0]]][1],a[c[0][c[0][0]]][2]);
			--c[0][0];
		}
		while(c[1][0]>n/2)
		{
			ans-=a[c[1][c[1][0]]][1];
			ans+=max(a[c[1][c[1][0]]][0],a[c[1][c[1][0]]][2]);
			--c[1][0];
		}
		while(c[2][0]>n/2)
		{
			ans-=a[c[2][c[2][0]]][2];
			ans+=max(a[c[2][c[2][0]]][0],a[c[2][c[2][0]]][1]);
			--c[2][0];
		}
		printf("%d\n",ans);
		c[0][0]=c[1][0]=c[2][0]=0;
	}
	return 0;
}