#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],x[100005],ans;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		bool p=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(c[i]!=0) p=1;
			x[i]=b[i]-a[i],ans+=a[i];
		}
		if(!p)
		{
			sort(x+1,x+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=x[i];
			printf("%d\n",ans);
		}
		else
		{
			if(n==2)
			{
				int a1=a[1]+max(b[2],c[2]);
				int a2=b[1]+max(a[2],c[2]);
				int a3=c[1]+max(a[2],b[2]);
				printf("%d\n",max(a3,max(a1,a2)));
			}
			else
			{
				int sum=0;
				for(int i=1;i<=n;i++) sum+=max(a[i],max(b[i],c[i]));
				printf("%d\n",sum);
			}
		}
	}
	return 0;
}
