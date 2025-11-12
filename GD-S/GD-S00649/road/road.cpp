#include<bits/stdc++.h>
using namespace std;
#define N 10001000
struct abc
{
	int u,v,c;
	long long w;
}a[N];
int x;
int abc(abc x1,abc x2)
{
	return x1.w<x2.w;
}
int fa[N];
int find(int x)
{
	if(fa[x]==x)
	  return x;
	return fa[x]=find(fa[x]);
}
int q[20];
int q1[20];
int v[20];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n+k+1;i++)
	  fa[i]=i;
	for(int i=1;i<=m;i++)
	  {
	  	x++;
	  	cin>>a[x].u>>a[x].v>>a[x].w;
	  	a[x].c=0;
	  }
	for(int i=1;i<=k;i++)
	  {
	  	cin>>q[i];
	  	long long minn=999999999;
	  	for(int j=1;j<=n;j++)
	  	  {
	  	  	x++;
	  	  	a[x].u=n+i;
	  	  	a[x].v=j;
	  	  	cin>>a[x].w;
	  	  	a[x].w=a[x].w+q[i];
	  	  	a[x].c=i;
	  	  	//cout<<a[x].u<<" "<<a[x].v<<" "<<a[x].w<<" "<<x<<endl;
			}
		/*for(int j=(x-n+1);j<=x;j++)
		  cout<<a[j].u<<" "<<a[j].v<<" "<<a[j].w<<" "<<j<<endl;\
		  */
	  }
	/*for(int i=m+1;i<=m+n*k;i++)
	  cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;
	for(int i=1;i<=k;i++)
	  cout<<q[i]<<endl;*/
	sort(a+1,a+m+k*n+1,abc);
	/*for(int i=1;i<=10;i++)
	  cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;
	cout<<endl;*/
	long long kk=0,w1=n;
	long long s=0;
	while(w1>1&&kk<=(m+k*n))
	  {
	  	kk++;
	  	int uu=a[kk].u;
	  	int vv=a[kk].v;
	  	int ww=a[kk].w;
	  	if(find(uu)==find(vv))
	  	  continue;
	  	w1=w1-1;
		fa[find(uu)]=vv;
		s=s+ww;
		if(uu>n&&v[(uu-n)]==0)
		  {
		  	w1++;
		  	v[uu-n]=1;
		  	for(int i=1;i<=m+k*n+1;i++)
		  	  if(a[i].c==(uu-n))
		  	    a[i].w=a[i].w-q[uu-n];
		  	sort(a+1,a+m+k*n+1,abc);
		  	kk=0;
		  }
		if(vv>n&&v[(vv-n)]==0)
		  {
		  	w1++;
		  	v[vv-n]=1;
		  	for(int i=1;i<=m+k*n+1;i++)
		  	  if(a[i].c==(vv-n))
		  	    a[i].w=a[i].w-q[vv-n];
		  	sort(a+1,a+m+k*n+1,abc);
		  	kk=0;
		  }
		//cout<<uu<<" "<<vv<<" "<<ww<<" "<<w1<<endl;
		///cout<<s<<endl;
	  }
	cout<<s<<endl;
	/*for(int i=1;i<=10;i++)
	  cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;*/
}
