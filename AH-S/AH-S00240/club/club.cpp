#include<bits/stdc++.h>
using namespace std;
int t,a[100005][3],b[100005],c[100005],d[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int n,ans=0,op0=0,op1=0,op2=0;
		scanf("%d",&n);
		int num=n/2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>=max(a[i][1],a[i][2]))
				b[++op0]=a[i][0]-max(a[i][1],a[i][2]),ans+=a[i][0];
			else if(a[i][1]>=max(a[i][0],a[i][2]))
				c[++op1]=a[i][1]-max(a[i][0],a[i][2]),ans+=a[i][1];
			else if(a[i][2]>=max(a[i][1],a[i][0]))
				d[++op2]=a[i][2]-max(a[i][0],a[i][1]),ans+=a[i][2];
		}
		if(op0>num)
		{
			sort(b+1,b+op0+1);
			for(int i=1;i<=op0-num;i++) ans-=b[i];
			printf("%d\n",ans);
		}
		else if(op1>num)
		{
			sort(c+1,c+op1+1);
			for(int i=1;i<=op1-num;i++) ans-=c[i];
			printf("%d\n",ans);
		}
		else if(op2>num)
		{
			sort(d+1,d+op2+1);
			for(int i=1;i<=op2-num;i++) ans-=d[i];
			printf("%d\n",ans);
		}
		else printf("%d\n",ans);
	}
	return 0;
}
