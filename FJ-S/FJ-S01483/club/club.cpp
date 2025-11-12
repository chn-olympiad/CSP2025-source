#include<bits/stdc++.h>
using namespace std;
struct node{
	int chao;
}b[3][100010];
int n,a[100010][3],res[3],ans;
bool cmp(node ss,node tt)
{
	return ss.chao<tt.chao;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		res[0]=res[1]=res[2]=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])
			{
				ans+=a[i][0];
				res[0]++;
				b[0][res[0]].chao=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
			}
			else if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][0])
			{
				res[1]++;
				ans+=a[i][1];
				b[1][res[1]].chao=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
			}
			else
			{
				res[2]++,ans+=a[i][2];
				b[2][res[2]].chao=min(a[i][2]-a[i][1],a[i][2]-a[i][0]);
			}
		}
		if(res[0]>(n/2))
		{	
			sort(b[0]+1,b[0]+res[0]+1,cmp);
			for(int i=1;i<=res[0]-(n/2);i++)
			{
				ans-=b[0][i].chao;
			}
		}
		if(res[1]>(n/2))
		{
			sort(b[1]+1,b[1]+res[1]+1,cmp);
			for(int i=1;i<=res[1]-(n/2);i++)
			{
				ans-=b[1][i].chao;
			}
		}
		if(res[2]>(n/2))
		{
			sort(b[2]+1,b[2]+res[2]+1,cmp);
			for(int i=1;i<=res[2]-(n/2);i++)
			{
				ans-=b[2][i].chao;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
