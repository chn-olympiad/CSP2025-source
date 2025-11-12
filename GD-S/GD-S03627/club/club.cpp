#include<bits/stdc++.h>
using namespace std;
int t,n,ans=-1;
struct node{
	int j[3],num;
}a[100005],h[100005],w[100005];
int v[100005];
void dfs(int i,int sum1,int sum2,int sum3,int num)
{
	if(num>ans) ans=num;
	if(i>n) return;
	if(sum1+1<=n/2)
	{
		dfs(i+1,sum1+1,sum2,sum3,num+a[i].j[0]);
	}
	if(sum2+1<=n/2)
	{
		dfs(i+1,sum1,sum2+1,sum3,num+a[i].j[1]);
	}
	if(sum3+1<=n/2)
	{
		dfs(i+1,sum1,sum2,sum3+1,num+a[i].j[2]);
	}
}
bool cmp(node a,node b)
{
	return a.j[0]>b.j[0];
}
bool cmp2(node a,node b)
{
	return a.j[1]>b.j[1];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(v,0,sizeof(v));
		ans=-1;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(h,0,sizeof(h));
		memset(w,0,sizeof(w));
		bool flag=true;
		bool flag2=true;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				scanf("%d",&a[i].j[j]);
				if(j!=0&&a[i].j[j]) flag=false;
			}
			if(a[i].j[2]!=0) flag2=false;
			a[i].num=i;
			h[i]=w[i]=a[i];
		}
		if(flag)
		{
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].j[0];
			}
			ans++;
		}
		else if(flag2)
		{
			sort(h+1,h+1+n,cmp);
			sort(w+1,w+1+n,cmp2);
			int ans1=0,ans2=0;
			int h1=1,h2=1;
			for(int i=1;i<=n;i++)
			{
				if(h[i].j[0]>h[i].j[1]&&h1<=n/2)
				{
					ans1+=h[i].j[0]; h1++;
				 }
				 else{
				 	ans1+=h[i].j[1];
				 }
			}
			for(int i=1;i<=n;i++)
			{
				if(w[i].j[1]>w[i].j[0]&&h2<=n/2)
				{
					ans2+=w[i].j[1];h2++;
				 }
				 else{
				 	ans2+=w[i].j[0];
				 }
			}
			ans=max(ans1,ans2);
		}
			
		else{
			dfs(1,0,0,0,0);
		}
		printf("%d\n",ans);
	}
	return 0;
} 
