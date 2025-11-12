#include<bits/stdc++.h>
using namespace std;
int n,a[100005][5];
bool A=1,B=1;
long long f[50004][50004],ans;
int read()
{
	int x=0,b=1;
	char c=getchar();
	while(c<'0'||'9'<c)
	{
		if(c=='-') b=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*b;
}
void dfs(int p,int vf,int vs,int vt,long long valua)
{
	if(p>n)
	{
		ans=max(ans,valua);
		return;
	}
	if(vf<n/2) dfs(p+1,vf+1,vs,vt,valua+a[p][1]);
	if(vs<n/2) dfs(p+1,vf,vs+1,vt,valua+a[p][2]);
	if(vt<n/2) dfs(p+1,vf,vs,vt+1,valua+a[p][3]);
	return; 
} 
void solve()
{
	n=read(); 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++) a[i][j]=read();
		if(a[i][2]!=0||a[i][3]!=0) A=0;
		if(a[i][3]!=0) B=0;
	}
	
	ans=0;
	if(A)
	{
		int f[100005];
		for(int i=1;i<=n;i++) f[i]=a[i][1];
		sort(f+1,f+n+1);
		for(int i=n;i>n/2;i--) ans+=f[i];
		cout<<ans;
		return;
	}
    
    //cout<<"fjkffhk";
    
    if(n<=25)
    {
		dfs(0,0,0,0,0);
    	cout<<ans<<endl;
    	return;
    }
    
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			f[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int x=min(n/2,i);x>=0;x--)
		{
			for(int y=min(n/2,i-x);y>=0;y--)
			{
				if(i-x-y>n/2) break;
				if(x>=1) f[x][y]=max(f[x][y],f[x-1][y]+a[i][1]);
				if(y>=1) f[x][y]=max(f[x][y],f[x][y-1]+a[i][2]);
				if(i-x-y>=1) f[x][y]=max(f[x][y],f[x][y]+a[i][3]);	
				if(i==n) ans=max(ans,f[x][y]);
				//cout<<x<<' '<<y<<' '<<f[x][y]<<endl;
			}
		}
	}
	cout<<ans<<endl;
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	t=read(); 
	while(t--) solve();
	return 0;
}
