#include<bits/stdc++.h>
using namespace std;
int a[100010][10];
struct qwq
{
	int pos;
	int c1,c2;
}b[100010];
bool cmp(qwq x,qwq y)
{
	return min(x.c1,x.c2)<=min(y.c1,y.c2);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,sizeof(a),0);
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			//cin>>a[i][1]>>a[i][2]>>a[i][3];
			scanf("%d",&a[i][1]);
			scanf("%d",&a[i][2]);
			scanf("%d",&a[i][3]);
			int p=2;
			if(a[i][1]>=a[i][2]||a[i][3]>=a[i][2])
			{
				if(a[i][1]>=a[i][3])
				{
					p=1;
				}
				else
				{
					p=3;
				}
			}
			a[i][4]=p;
		}
		int cnt[4];
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		for(int i=1;i<=n;i++)
		{
			cnt[a[i][4]]++;
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i][a[i][4]];
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2)
		{
			cout<<ans<<endl;
			continue;
		}
		int m;
		if(cnt[1]>n/2)
		{
			m=1;
		}
		if(cnt[2]>n/2)
		{
			m=2;
		}
		if(cnt[3]>n/2)
		{
			m=3;
		}
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][4]==m)
			{
				b[++tot].pos=i;
				int b1=(a[i][4]+1)%3,b2=(a[i][4]+2)%3;
				if(b1==0)
				{
					b1=3;
				}
				if(b2==0)
				{
					b2=3;
				}
				b[tot].c1=a[i][a[i][4]]-a[i][b1];
				b[tot].c2=a[i][a[i][4]]-a[i][b2];
			}
		}
		/*for(int i=1;i<=tot;i++)
		{
			cout<<b[i].pos<<' '<<b[i].c1<<' '<<b[i].c2<<endl;
		}*/
		sort(b+1,b+1+tot,cmp);
		/*for(int i=1;i<=tot;i++)
		{
			cout<<b[i].pos<<' '<<b[i].c1<<' '<<b[i].c2<<endl;
		}*/
		for(int i=1;i<=cnt[m]-n/2;i++)
		{
			ans-=min(b[i].c1,b[i].c2);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
