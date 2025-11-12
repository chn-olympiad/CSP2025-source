#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7,M=5;
int read()
{
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
	return x*y;
}
int n,a[N][M],num[M];
int xx[N],yy[N],ss[N];
int qmax(int i)
{
	if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])return 1;
	if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])return 2;
	return 3;
}
int qmid(int i,int j)
{
	if(j==1)return a[i][2]>=a[i][3]?2:3;
	if(j==2)return a[i][1]>=a[i][3]?1:3;
	return a[i][1]>=a[i][2]?1:2;
}
int aaa[N],ans;
void work(int t)
{
	int m=0;
	for(int i=1;i<=n;i++)
		if(ss[i]==t)aaa[++m]=a[i][xx[i]]-a[i][yy[i]];
	sort(aaa+1,aaa+1+m);
	for(int i=1;i<=m-(n/2);i++)
		ans-=aaa[i],num[t]--;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();for(;T;T--)
	{
		n=read(),num[1]=num[2]=num[3]=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)a[i][j]=read();
			xx[i]=qmax(i),yy[i]=qmid(i,xx[i]);
			ans+=a[i][xx[i]],num[xx[i]]++,ss[i]=xx[i];
		}
		for(int i=1;i<=3;i++)
			if(num[i]>n/2)
			{
				work(i);
				break;
			}
		printf("%d\n",ans);
	}
	return 0;
}