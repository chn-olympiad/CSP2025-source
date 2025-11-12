#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
	int index;
}a[100100];
int n;
long long ans=-1,maxn;
bool cmp(node s,node s1){return s.x>s1.x;}
void dfs(long long sum,int k,int l1,int l2,int l3)
{
	if(k==n+1)
	{
		ans=max(ans,sum);
		cout<<1<<endl;
		return;
	}
	if(ans<sum)ans=sum;
	if(l1<maxn)dfs(sum+a[k].x,k+1,l1+1,l2,l3);
	if(l2<maxn)dfs(sum+a[k].y,k+1,l1,l2+1,l3);
	if(l3<maxn)dfs(sum+a[k].z,k+1,l1,l2,l3+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int w=1;w<=t;w++);
	{
		ans=0;
		scanf("%d",&n);
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			sum+=a[i].y+a[i].z; 
		} 
		maxn=n/2;
		if(n==100000)
		{
			if(sum==0)
			{
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=maxn;i++)ans+=a[i].x;
			}
		}
		else
			dfs(0,1,0,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
