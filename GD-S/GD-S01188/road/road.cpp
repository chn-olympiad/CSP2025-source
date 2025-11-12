#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[100000],ans,v[11],kk[11],kkk[11],flag=0;
struct node
{
	long long r,l,s,z;
}a[10000000];
long long find(long long x)
{
	int y;
	if(fa[x]==x)
	return x;
	else
	 y=find(fa[x]);
	return y;
}
bool cmp(node x,node y)
{
	return x.s<y.s;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		
		int d,b,c;
		cin>>d>>b>>c;
		a[i].r=d;
		a[i].l=b;
		a[i].s=c;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>kk[i];
		for(int j=1;j<=n;j++)
		{
			int d;
			cin>>d;
			m++;
			fa[n+i]=n+i;
			a[m].l=n+i;a[m].r=j;a[m].s=d+kk[i];a[m].z=i;
		}
	}
	sort(a+1,a+m,cmp);
	for(int i=1;i<m;i++)
	//cout<<a[i].r<<" "<<a[i].l<<" "<<a[i].s<<" "<<a[i].z<<endl;
	for(int i=1;i<m;i++)
	{
		if(flag==n-1)
		break;
		if(find(a[i].r)!=find(a[i].l))
		{
			if(a[m].z==0)
			{
			ans+=a[i].s;
		//	cout<<a[i].s<<" ";
			fa[find(a[i].l)]=find(a[i].r);
			flag++;
		}
		else
		{
			ans+=a[i].s;
			fa[find(a[i].l)]=find(a[i].r);
			v[max(a[i].r,a[i].l)-n]++;kkk[max(a[i].r,a[i].l)-n]=a[i].s;
			if(v[max(a[i].r,a[i].l)-n]>1)
			flag++;
			if(v[max(a[i].r,a[i].l)-n]==1)
			{
				for(int j=i+1;j<m;j++)
				if(a[j].z==(max(a[i].r,a[i].l)-n))
				a[j].s-=kk[max(a[i].r,a[i].l)-n];
				sort(a+i+1,a+m,cmp);
			}
			//cout<<a[i].s<<" ";
		}
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(v[i]==1)
		ans=ans-kkk[i];
		//if(v[i]>1)
		//ans=ans-(v[i]-1)*kk[i];
	}
/*	for(int i=1;i<=k;i++)
	cout<<i<<" "<<kk[i]<<" "<<v[i]<<" "<<kkk[i]<<endl;*/
	cout<<ans;
	return 0;
}
