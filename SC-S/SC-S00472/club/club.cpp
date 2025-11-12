#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,sel[N],w[N][5],cnt[5],en[5],s[N],tot;
long long ans;
struct node{int num,k;}e[5][N];
bool cmp(node x,node y)
{
	if(x.num!=y.num) return x.num>y.num;
	return x.k<y.k;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(sel,0,sizeof sel);
		memset(s,0,sizeof s);
		tot=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				int x; cin>>x;
				e[j][i]={x,i};
				w[i][j]=x;
				if(x) s[++tot]=x;
			}
		}
		if(tot==n)
		{
			sort(s+1,s+1+tot);
			for(int i=1;i<=n;i++) ans+=s[i];
			cout<<ans<<'\n';
		} 
		if(tot==2*n)
		{
			long long a=0,b=0;
			for(int i=1;i<=2;i++)
			{
				sort(e[i]+1,e[i]+1+n,cmp);
				for(int j=1;j<=n/2;j++)
					if(i==1) a+=e[i][j].num;
					else b+=e[i][j].num;
			}
			if(a>b)
			{
				for(int i=1;i<=n/2;i++)
					sel[e[1][i].k]=1;
				for(int i=1;i<=n;i++)
					if(!sel[i]) ans+=w[i][2];
				ans+=a;
			}
			else if(a<b) 
			{
				for(int i=1;i<=n/2;i++)
					sel[e[2][i].k]=1;
				for(int i=1;i<=n;i++)
					if(!sel[i]) ans+=w[i][1];
				ans+=b;
			}
			else
			{
				ans=a;a=0,b=0;
				for(int i=1;i<=2;i++)
				{
				for(int j=n/2+1;j<=n;j++)
					if(i==1) a+=e[i][j].num;
					else b+=e[i][j].num;
				}
				ans+=max(a,b);
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}