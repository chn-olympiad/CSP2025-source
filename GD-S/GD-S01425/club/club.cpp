#include<bits/stdc++.h>
using namespace std;
int n,t,f[100005][5],d[5],ans;
struct xx
{
	int a[5];
}a[100005];
bool c1(xx x,xx y)
{
	return x.a[1]<y.a[1];
}
bool c2(xx x,xx y)
{
	return x.a[2]<y.a[2];
}
bool c3(xx x,xx y)
{
	return x.a[3]<y.a[3];
}
void dfs(int x,int q,int w,int e,int s)
{
	if(x==n+1)
	{
		ans=max(ans,s);
	}
	if(q<n/2)dfs(x+1,q+1,w,e,s+a[x].a[1]);
	if(w<n/2)dfs(x+1,q,w+1,e,s+a[x].a[2]);
	if(e<n/2)dfs(x+1,q,w,e+1,s+a[x].a[3]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(f,0,sizeof(f));
		memset(d,0,sizeof(d));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].a[1]>>a[i].a[2]>>a[i].a[3];
		if(n<=10)
		{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
			continue;
		}
		bool q=1;
		for(int i=1;i<=n;i++)if(a[i].a[2]||a[i].a[3])
		{
			q=0;
			break;
		}
		if(q)
		{
			sort(a+1,a+n+1,c1);
			for(int i=1;i<=n/2;i++)ans+=a[i].a[1];
			cout<<ans<<endl;
			continue;
		}
		
		memset(f,0,sizeof(f));
		sort(a+1,a+n+1,c1);
		for(int i=n;i>n/2;i--)d[1]+=a[i].a[1];
		for(int i=1;i<=n/2;i++)for(int j=2;j<=3;j++)for(int k=2;k<=3;k++)f[i][j]=max(f[i][j],f[i-1][k]+a[i].a[j]);
		ans=max(ans,d[1]+max(f[n/2][2],f[n/2][3]));
		
		memset(f,0,sizeof(f));
		sort(a+1,a+n+1,c2);
		for(int i=n;i>n/2;i--)d[2]+=a[i].a[2];
		for(int i=1;i<=n/2;i++)for(int j=1;j<=3;j++)for(int k=1;k<=3;k++)if(j!=2&&k!=2)f[i][j]=max(f[i][j],f[i-1][k]+a[i].a[j]);
		ans=max(ans,d[2]+max(f[n/2][1],f[n/2][3]));
		
		memset(f,0,sizeof(f));
		sort(a+1,a+n+1,c3);
		for(int i=n;i>n/2;i--)d[3]+=a[i].a[3];
		for(int i=1;i<=n/2;i++)for(int j=1;j<=2;j++)for(int k=1;k<=2;k++)f[i][j]=max(f[i][j],f[i-1][k]+a[i].a[j]);
		ans=max(ans,d[3]+max(f[n/2][1],f[n/2][2]));
		cout<<ans<<endl;
	}
	
}

