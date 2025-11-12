#include<bits/stdc++.h>
using namespace std;
const int N=505,M=998244353;
int n,m,f[262201][20],a[N],b[N],dl[262201];char ch[N];bool bj[262201];
long long ans;
void add(int &x,int y)
{
	x+=y;
	if(x>=M)
	x-=M;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,S,j,head=0,tail=1,x;
	scanf("%d%d%s",&n,&m,ch);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	b[i]=ch[i]-'0';
	dl[1]=0;f[0][0]=1;
	while(head<tail)
	{
		S=dl[++head];
		x=0;
		for(i=0;i<n;i++)
		{
			if((S&(1<<i))!=0)
			x++;
		}
		for(i=0;i<=x;i++)
		{
			for(j=0;j<n;j++)
			{
				if((S&(1<<j))==0)
				{
					if(a[j]>x-i&&b[x]==1)
					add(f[S|(1<<j)][i+1],f[S][i]);
					else
					add(f[S|(1<<j)][i],f[S][i]);
					if(bj[S|(1<<j)]==0)
					{
						bj[S|(1<<j)]=1;dl[++tail]=S|(1<<j);
					}
				}
			}
		}
	}
	S=(1<<n)-1;
	for(i=m;i<=n;i++)
	ans+=f[S][i];
	ans=ans%M;
	printf("%lld",ans);
	return 0;
}
