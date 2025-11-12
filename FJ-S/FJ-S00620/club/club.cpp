#include<bits/stdc++.h>
using namespace std;;
int f[50010][4],z[4],t[4],a[100010][4],v[4],x[50010];
int zz()
{
	if(z[1]>z[2]&&z[1]>z[3])
		return 1;
	if(z[2]>z[1]&&z[2]>z[3])
		return 2;
	return 3;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int m,n,f1=1,f2=2,f3=3;
	cin>>m;
	while(m--)
	{
		t[1]=t[2]=t[3]=0;
		z[1]=z[2]=z[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			v[1]=a[i][1];v[2]=a[i][2];v[3]=a[i][3];
			f1=1;f2=2;f3=3;
			if(v[1]<v[2])
			{
				swap(v[1],v[2]);
				swap(f1,f2);
			}
			if(v[2]<v[3])
			{
				swap(v[2],v[3]);
				swap(f2,f3);
			}
			if(v[1]<v[2])
			{
				swap(v[1],v[2]);
				swap(f1,f2);
			}
			z[f1]++;t[f1]+=v[1];
			f[z[f1]][f1]=v[1]-v[2];
		}
		int ma=zz(),tt=t[1]+t[2]+t[3];
		if(z[ma]<=n/2)
		{
			cout<<tt<<endl;
			continue;
		}
		for(int i=1;i<=z[ma];i++)
			x[i]=f[i][ma];
		sort(x+1,x+1+z[ma]);
		for(int i=1;i<=z[ma]-(n/2);i++)
			tt-=x[i];
		cout<<tt<<endl;
	}
	return 0;
}