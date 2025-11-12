#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll t,n,i,j,ans,f1,id1,id2;
ll a[N][5],id[N],mx[N],sum[N],mx2[N],f[N];
struct node
{
	ll id,Mx,Mx2;
}b[N];
priority_queue<int,vector<int>,greater<int> > q[5];
void work(int i)
{
	int MX=a[i][1];
	id[i]=1,mx[i]=a[i][1],mx2[i]=-1;
	if(a[i][2]>MX) mx2[i]=mx[i],mx[i]=a[i][2],id[i]=2,MX=a[i][2];
	else mx2[i]=a[i][2];
	if(a[i][3]>MX) mx2[i]=mx[i],mx[i]=a[i][3],id[i]=3;
	else mx2[i]=max(mx2[i],a[i][3]);
	if(!a[i][2]&&!a[i][3]) f1++;
}
void work1(int i)
{
	ll MX=a[i][1];
	b[i].id=1,b[i].Mx=a[i][1],b[i].Mx2=0;
	if(a[i][2]>MX) b[i].id=2,b[i].Mx2=b[i].Mx,b[i].Mx=a[i][2],MX=a[i][2];
	else b[i].Mx2=a[i][2];
	if(a[i][3]>MX) b[i].id=3,b[i].Mx2=b[i].Mx,b[i].Mx=a[i][3];
	else b[i].Mx2=max(b[i].Mx2,a[i][3]);
}
void solve1()
{
	for(i=1;i<=3;i++) 
	 for(j=1;j<=3&&j!=i;j++) 
	  ans=max(ans,a[1][i]+a[2][j]);
	cout<<ans<<"\n";
}
void solve2()
{
	for(i=1;i<=n;i++) sum[i]=a[i][1];
	sort(sum+1,sum+n+1);
	for(i=1;i<=n/2;i++) ans+=sum[i];
	cout<<ans<<"\n";
}
bool cmp(node x,node y)
{
	return x.Mx>y.Mx;
} 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(mx,0,sizeof(mx));
		memset(mx2,0,sizeof(mx2));
		memset(f,0,sizeof(f));
		memset(id,0,sizeof(id));
		memset(sum,0,sizeof(sum));
		ans=0;
		cin>>n;
		for(i=1;i<=n;i++) 
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			work(i);
			work1(i);
		}
		if(n==2) solve1();
		else if(f1==n) solve2();
		else 
		{
			for(i=1;i<=3;i++) while(!q[i].empty()) q[i].pop();
			sort(b+1,b+n+1,cmp);
			for(i=1;i<=n;i++)
			{//cout<<id[i]<<' '<<mx[i]<<' '<<mx2[i]<<"\n";cout<<b[i].id<<' '<<b[i].Mx<<' '<<b[i].Mx2<<"\n";
				if(q[id[i]].size()<n/2) q[id[i]].push(b[i].Mx),f[b[i].Mx]=i;
				else 
				{
					ll maxn=-1,idj,idi,mn,d=q[id[i]].top();
					node e;
					e.Mx=d,e.id=f[d];
					if(mx2[f[d]]==e.Mx)e.Mx2=min(a[e.id][1],min(a[e.id][2],a[e.id][3]));
					else e.Mx2=0;
					if(b[i].Mx-b[i].Mx2-(e.Mx-e.Mx2)>maxn) 
					{
						maxn=b[i].Mx-b[i].Mx2-(e.Mx-e.Mx2),idj=j,idi=id1,mn=e.Mx;
						ll maxnn=-1;
						for(j=1;j<=3&&j!=id[i];j++)
						 if(a[e.id][j]>maxnn) maxnn=a[e.id][j],idj=j;
						q[id[i]].pop();
						q[idj].push(mn);
						q[id[i]].push(b[i].Mx2);
					}
					else 
					{
						ll maxnn=-1;
						for(j=1;j<=3&&j!=id[i];j++)
						if(a[b[i].id][j]>maxnn) maxnn=a[b[i].id][j],idj=j;
						q[idj].push(b[i].Mx2);
					}
				}
			}	
			for(i=1;i<=3;i++)
				while(!q[i].empty())
				{
					ans+=q[i].top();
					q[i].pop();
//					cout<<ans<<" "<<i<<"\n";
				}
			cout<<ans<<"\n";
		}
	}
	return 0;
 }
