#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
/*int x[100005],y[100005],z[100005];
int d[100005],e[100005],f[100005];//ab bc ca
int a1=0,b1=0,c1=0,a2=0,b2=0,c2=0;*/
int ans=0,n=0;
void dfs(int x,int ma,int a1,int b1,int c1)
{
	if(x>n)ans=max(ma,ans);
	if(a1<n/2)dfs(x+1,ma+a[x],a1+1,b1,c1);
	if(b1<n/2)dfs(x+1,ma+b[x],a1,b1+1,c1);
	if(c1<n/2)dfs(x+1,ma+c[x],a1,b1,c1+1);
	return;
}
/*void p(int k,int l){
	if(k>4)return;
	if(a1>n/2-a2)
	{
		k=0;
		for(int i=1;i<a1;i++)
	}
	if(b1>n/2-b2)
	{
		k=0;
	}
	if(c1>n/2-c2)
	{
		k=0;
	}
	p(k+1,(l+1)%3);
	return;
}*/
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i]>>c[i];
/*		for(int i=1,j=0;i<=n;i++)
		{
			j=max(a[i],max(b[i],c[i]));
			ans+=j;
			if(j==a[i])
			{
				a1++;
				x[a1]=i;
			}
			else if(j==b[i])
			{
				b1++;
				y[b1]=i;
			}
			else {
				c1++;
				z[c1]=i;
			}
			d[i]=a[i]-b[i];
			e[i]=b[i]-c[i];
			f[i]=c[i]-a[i];
		}
		p(0);*/
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++){
			a[i]=0;b[i]=0;c[i]=0;
		}
		ans=0;/*a1=0;b1=0;c1=0;*/
	}
	return 0;
}

