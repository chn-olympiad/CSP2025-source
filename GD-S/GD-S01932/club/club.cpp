#include<bits/stdc++.h>
using namespace std;
#define N 100010
int T,z[N][3],n,x[N],s[3],ans;
void dfs(int w)
{
	if(w==n+1)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
			sum+=z[i][x[i]];
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<=2;i++)
		if(s[i]+1<=n/2)
		{
			s[i]++;
			x[w]=i;
			dfs(w+1);
			s[i]--;
		}
}
bool pd()
{
	for(int i=1;i<=n;i++) if(z[i][1]||z[i][2]) return 0; 
	return 1;
}
int xs[N];
int k[N];
bool cmp(int a,int b){return a>b;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>z[i][0]>>z[i][1]>>z[i][2];
		if(n<=30)
		{
			s[0]=s[1]=s[2]=0;
			ans=0;
			dfs(1);
			cout<<ans<<'\n';
		}
		else if(pd())
		{
			for(int i=1;i<=n;i++) xs[i]=z[i][0];
			sort(xs+1,xs+1+n);
			int ans=0;
			for(int i=n;i>n/2;i--) ans+=xs[i];
			cout<<ans<<'\n';
		}
		else
		{
			for(int i=1;i<=n;i++) k[i]=max({z[i][0],z[i][1],z[i][2]});
			sort(k+1,k+1+n,cmp);
			int ans=0;
			for(int i=1;i<=n;i++) ans+=k[i];
			cout<<ans<<'\n';
		}
	}
 } 

