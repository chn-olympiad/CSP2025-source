#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005][3],b[100005];
int st[3][100005],num[3];
void qsort(int x,int l,int r)
{
	if(l>=r) return;
	int i=l,j=r; const int mid=rand()%(r-l+1)+l;
	int mid1=b[st[x][mid]];
	while(i<=j)
	{
		while(b[st[x][i]]>mid1) i++;
		while(b[st[x][j]]<mid1) j--;
		if(i<=j)
		{
			swap(st[x][i],st[x][j]);
			i++; j--;
		}
	}
	qsort(x,i,r); qsort(x,l,j);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	srand(time(0));
	int T; scanf("%d",&T);
	for(int iii=1;iii<=T;iii++)
	{
		scanf("%d",&n); num[0]=num[1]=num[2]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=2;j++)
				scanf("%d",&a[i][j]);
			int maxn=max(a[i][0],max(a[i][1],a[i][2]));
			int maxn2=a[i][0]+a[i][1]+a[i][2]-maxn-min(a[i][0],min(a[i][1],a[i][2]));
			b[i]=maxn-maxn2;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int maxn=0,max2;
			for(int j=0;j<=2;j++)
			{
				if(maxn<a[i][j])
				{
					maxn=a[i][j]; max2=j;
				}
			}
			st[max2][++num[max2]]=i;
			ans+=maxn;
		}
		for(int i=0;i<=2;i++)
		{
			if(num[i]>n/2)
			{
				qsort(i,1,num[i]);
				while(num[i]>n/2) ans-=b[st[i][num[i]--]];
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
 } 
 /*
 3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

 */
