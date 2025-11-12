#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,b[100005],c[100005],d[100005],flags[100005];
struct st{
	int s,xu;	
}p[100005];
struct node{
	int x,y,z;
}a[100005];
int solve(int b[],int o)
{
	int cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(b[i]>=0) p[++cnt]={b[i],i}; 
	}
	sort(p+1,p+cnt+1,[&](st l1,st l2){return l1.s>l2.s;});
	for(int i=1;i<=n/2;i++){
		if(o==1) sum+=a[p[i].xu].x;
		else if(o==2) sum+=a[p[i].xu].y;
		else sum+=a[p[i].xu].z;
		flags[p[i].xu]=1;
	}
	for(int i=1;i<=n;i++){
		if(!flags[i])
		{
			if(o==1) sum+=max(a[i].y,a[i].z);
			else if(o==2) sum+=max(a[i].x,a[i].z);
			else sum+=max(a[i].x,a[i].y);
		}
	}
	for(int i=1;i<=n;i++) flags[i]=0;
	return sum;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		int s1=0,s2=0,s3=0;
		for(int i=1;i<=n;i++){
			b[i]=a[i].x-max(a[i].y,a[i].z),s1+=(b[i]>=0);
			c[i]=a[i].y-max(a[i].x,a[i].z),s2+=(c[i]>=0);
			d[i]=a[i].z-max(a[i].x,a[i].y),s3+=(d[i]>=0);
		}
		int ans=0;
		if(s1>n/2) ans=solve(b,1);
		if(s2>n/2) ans=solve(c,2);
		if(s3>n/2) ans=solve(d,3);
		if(!ans)
		{
			for(int i=1;i<=n;i++){
				ans+=max(max(a[i].x,a[i].y),a[i].z);
			}
		}
		cout<<ans<<endl;
		memset(b,0,sizeof(b)),memset(c,0,sizeof(c)),memset(d,0,sizeof(d));
	}
	return 0;
}
