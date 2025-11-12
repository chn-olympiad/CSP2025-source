#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data,id;
}b1[100010],b2[100010],b3[100010];
int a1,a2,a3,c[100010],d[100010],sum[5];
bool cmp(node a,node b)
{
	if(c[a.id]==c[b.id])
	{
		return a.data<b.data;
	}
	return c[a.id]<c[b.id];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,n1=0,n2=0,n3=0;
		cin>>n;
		memset(sum,0,sizeof(sum));
		memset(b1,0,sizeof(b1));
		memset(b2,0,sizeof(b2));
		memset(b3,0,sizeof(b3));
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a1,&a2,&a3);
			if(a1>a2&&a1>a3)
			{
				b1[++n1].id=i;
				b1[n1].data=a1;
				sum[1]+=b1[n1].data;
				c[i]=a1-max(a2,a3);
				d[i]=a2>a3?2:3;
			}
			else if(a2>a3)
			{
				b2[++n2].id=i;
				b2[n2].data=a2;
				sum[2]+=b2[n2].data;
				c[i]=a2-max(a1,a3);
				d[i]=a1>a3?1:3;
			}
			else
			{
				b3[++n3].id=i;
				b3[n3].data=a3;
				sum[3]+=b3[n3].data;
				c[i]=a3-max(a1,a2);
				d[i]=a1>a2?1:2;
			}
		}
		if(n1>n/2)
		{
			sort(b1+1,b1+n1+1,cmp);
			for(int i=1;n1-i>=n/2;i++)
			{
				sum[1]-=b1[i].data;
				sum[d[i]]+=b1[i].data-c[b1[i].id];
			}
		}
		else if(n2>n/2)
		{
			sort(b2+1,b2+n2+1,cmp);
			for(int i=1;n2-i>=n/2;i++)
			{
				sum[2]-=b2[i].data;
				sum[d[i]]+=b2[i].data-c[b2[i].id];
			}
		}
		else if(n3>n/2)
		{
			sort(b3+1,b3+n3+1,cmp);
			for(int i=1;n3-i>=n/2;i++)
			{
				sum[3]-=b3[i].data;
				sum[d[i]]+=b3[i].data-c[b3[i].id];
			}
		}
		cout<<sum[1]+sum[2]+sum[3]<<'\n';
	}
	return 0;
}
