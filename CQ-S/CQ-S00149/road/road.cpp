#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,f[N],siz[N],p[15],top,top1,sum1,g,top2;
long long ans,sum;
struct node{
	int l,r,z;
}a[N],qwq[15][10005],po[N],pw[N];
bool cmp(node i,node j)
{
	return i.z<j.z;
}
int find(int i)
{
	if(f[i]==i) return i;
	return f[i]=find(f[i]); 
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
		cin>>a[i].l>>a[i].r>>a[i].z;
	for(int i=1;i<=k;++i)
	{
		cin>>p[i];
		for(int j=1;j<=n;++j)
			cin>>po[j].z,po[j].l=n+i,po[j].r=j;
		sort(po+1,po+n+1,cmp);
		for(int j=1;j<=n;++j)
			qwq[i][j]=po[j];
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;++i)
		siz[i]=1,f[i]=i;
	for(int i=1;i<=m;++i)
	{
		if(find(a[i].l)!=find(a[i].r))
		{
			++top2;
			pw[top2]=a[i];
			f[f[a[i].l]]=f[a[i].r]; 
		}
	}
	ans=1e18;
	for(int i=0;i<(1<<k);++i)
	{
		top=sum=0;
		g=n;
		for(int j=1;j<=k;++j)
		{
			if((1<<(j-1))&i) 
			{
				for(int z=1;z<=n;++z)
					++top,po[top]=qwq[j][z];
				++g;
				sum+=p[j];
			}
		}
		sort(po+1,po+top+1,cmp);
		top1=1;
		for(int j=1;j<=n+k;++j)
			f[j]=j,siz[j]=1;
		sum1=0;
		for(int j=1;j<=top2;++j)
		{
			while(po[top1].z<=pw[j].z&&top1<=top)
			{
				if(find(po[top1].l)!=find(po[top1].r))
				{
					sum+=po[top1].z;
					++sum1;
					if(siz[f[po[top1].l]]>siz[f[po[top1].r]])
						f[f[po[top1].r]]=f[po[top1].l],siz[f[po[top1].l]]+=siz[f[po[top1].r]];
					else
						f[f[po[top1].l]]=f[po[top1].r],siz[f[po[top1].r]]+=siz[f[po[top1].l]];
					if(sum1==g) break; 
				}
				++top1;
			}
			if(sum1==g) break;
			if(find(pw[j].l)!=find(pw[j].r))
			{
				sum+=pw[j].z;
				++sum1;
				if(siz[f[pw[j].l]]>siz[f[pw[j].r]])
					f[f[pw[j].r]]=f[pw[j].l],siz[f[pw[j].l]]+=siz[f[pw[j].r]];
				else
					f[f[pw[j].l]]=f[pw[j].r],siz[f[pw[j].r]]+=siz[f[pw[j].l]];
			} 
			if(sum1==g) break;
		}
		ans=min(ans,sum);
	}
	cout<<ans<<'\n';
	return 0;
 } 
