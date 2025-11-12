#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
bool flag[100005];
struct Q{
	int val;
	int i;
}q[100005];
struct W{
	int val;
	int i;
}w[100005];
struct E{
	int val;
	int i;
}e[100005];
bool cmp1(Q x,Q y)
{
	return x.val>y.val;
}
bool cmp2(W x,W y)
{
	return x.val>y.val;
}
bool cmp3(E x,E y)
{
	return x.val>y.val;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			flag[i]=0;
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		for(int i=1;i<=n;i++)
		{
			q[i].val=a[i][1];
			q[i].i=i;
			w[i].val=a[i][2];
			w[i].i=i;
			e[i].val=a[i][3];
			e[i].i=i;
		}
		sort(q+1,q+n+1,cmp1);
		sort(w+1,w+n+1,cmp2);
		sort(e+1,e+n+1,cmp3);
		for(int i=n-1;i>=n/2-1;i--)
		{
			if(q[i].i==w[i].i&&w[i].i==e[i].i)
			{
				if(q[i].val+w[i+1].val+e[i+1].val>q[i+1].val+w[i].val+e[i+1].val&&q[i].val+w[i+1].val+e[i+1].val>q[i+1].val+w[i+1].val+e[i].val)
					w[i].i=q[i+1].i,w[i].val=w[i+1].val,e[i].i=e[i+1].i,e[i].val=e[i+1].val;
				else if(w[i].val+q[i+1].val+e[i+1].val>q[i].val+w[i+1].val+e[i+1].val&&w[i].val+q[i+1].val+e[i+1].val>q[i+1].val+w[i+1].val+e[i].val)
					e[i].i=e[i+1].i,e[i].val=e[i+1].val,q[i].i=q[i+1].i,q[i].val=q[i+1].val;
				else
					w[i].i=q[i+1].i,w[i].val=w[i+1].val,q[i].i=q[i+1].i,q[i].val=q[i+1].val;
			}
			else
			{
				if(q[i].i==w[i].i) 
				{
					if(q[i].val+w[i+1].val>q[i+1].val+w[i].val) w[i].val=w[i+1].val,w[i].i=w[i+1].i;
					else q[i].i=q[i+1].i,q[i].val=q[i+1].val;
				}
				else if(w[i].i==e[i].i) 
				{
					if(w[i].val+e[i+1].val>w[i+1].val+e[i].val) e[i].val=e[i+1].val,e[i].i=e[i+1].i;
					else w[i].i=w[i+1].i,w[i].val=w[i+1].val;
				}
				else if(q[i].i==e[i].i) 
				{
					if(q[i].val+e[i+1].val>q[i+1].val+e[i].val) e[i].val=e[i+1].val,e[i].i=e[i+1].i;
					else q[i].i=q[i+1].i,q[i].val=q[i+1].val;
				}
			}
			//if(q[i].i==w[i].i||q[i].i==e[i].i||w[i].i==e[i].i) i++;
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(q[i].i==w[i].i||q[i].i==e[i].i||w[i].i==e[i].i)
			{
				if(q[i].i==w[i].i&&q[i].i==e[i].i) 
				{
					if(flag[q[i].i]==0) ans+=max(q[i].val,max(w[i].val,e[i].val));flag[q[i].i]=1;
				}
				else if(q[i].i==w[i].i) 
				{
					if(flag[q[i].i]==0)
					ans+=max(q[i].val,w[i].val);
					flag[q[i].i]=1;
					if(flag[e[i].i]==0) ans+=e[i].val,flag[e[i].i]=1;
				}
				else if(e[i].i==w[i].i) 
				{
					if(flag[e[i].i]==0)
					ans+=max(e[i].val,w[i].val);
					flag[e[i].i]=1;
					if(flag[q[i].i]==0) ans+=q[i].val,flag[q[i].i]=1;
				}
				else if(q[i].i==e[i].i) 
				{
					if(flag[q[i].i]==0)
					ans+=max(q[i].val,e[i].val);
					flag[q[i].i]=1;
					if(flag[w[i].i]==0) ans+=w[i].val,flag[w[i].i]=1;
				}
			}
			else 
			{
				if(flag[q[i].i]==0)
					ans+=q[i].val,flag[q[i].i]=1;
				if(flag[w[i].i]==0)
					ans+=w[i].val,flag[w[i].i]=1;
				if(flag[e[i].i]==0)
					ans+=e[i].val,flag[e[i].i]=1;
			}
			//cout<<ans<<"\n";
		}
		printf("%lld\n",ans);
		//for(int i=1;i<=n;i++)
		//{
		//	cout<<q[i].i<<" "<<w[i].i<<" "<<e[i].i<<"\n";
		//}
	}
	return 0;
} 