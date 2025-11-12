//我常常追忆过去。 
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
int n,m,cnt=0;
struct op{int exam,id;}a[N];
bool cmp(op x,op y){return x.exam<y.exam;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[(i-1)*m+j].exam);
			a[(i-1)*m+j].id=(i-1)*m+j;
		}
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[++cnt].id==1)
			{
				if(j%2==0)printf("%d %d",j,n-i+1);
				else printf("%d %d",j,i);
				return 0;
			}
	return 0;
}
