#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10000001],n,m,j,k,l,c[1000000],d,x,y,ans,sum=1e17;
struct pp{
	int x,y,z;
}b[1000001];
int cmp(pp a,pp b){
	if(a.x==b.x)return a.z<b.z;
	return a.x<b.x;
}
main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			d=a[i];
			for(int k=i+1;k<=j;k++)
			{
			    d^=a[k];
			}
			if(d==m)ans++,b[++k].x=i,b[k].y=j,b[k].z=j-i+1;
		}
	}
	sum=0;
	sort(b+1,b+k+1,cmp);
	for(int i=1;i<=k;i++)
	{
		x=b[i].y;
		ans=1;
		for(int j=2;j<=k;j++)
		{
			if(b[j].x>x)ans++,x=b[j].y;
		}
		sum=max(sum,ans);
	} 
	cout<<sum;
}
