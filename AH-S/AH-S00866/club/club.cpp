#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][6],b[N],c[6];
int t,n,x,y,z,i,j;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(c,0,sizeof(c));
		j=0;
		z=0;
		for(i=1;i<=n;++i)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			x=max(max(a[i][1],a[i][2]),a[i][3]);
			z+=x;
			if(x==a[i][1])c[1]++;
			else if(x==a[i][2])c[2]++;
			else c[3]++;
		}
		if(c[1]>n/2)
		{
			y=c[1]-n/2;
			for(i=1;i<=n;++i)
			{
				x=max(max(a[i][1],a[i][2]),a[i][3]);
				if(x==a[i][1])
				{
					++j;
					b[j]=x-max(a[i][2],a[i][3]);
				}
			}
			sort(b+1,b+j+1);
			for(i=1;i<=y;++i)z-=b[i];
		}
		else if(c[2]>n/2)
		{
			y=c[2]-n/2;
			for(i=1;i<=n;++i)
			{
				x=max(max(a[i][1],a[i][2]),a[i][3]);
				if(x==a[i][2])
				{
					++j;
					b[j]=x-max(a[i][1],a[i][3]);
				}
			}
			sort(b+1,b+j+1);
			for(i=1;i<=y;++i)z-=b[i];
		}
		else if(c[3]>n/2)
		{
			y=c[3]-n/2;
			for(i=1;i<=n;++i)
			{
				x=max(max(a[i][1],a[i][2]),a[i][3]);
				if(x==a[i][3])
				{
					++j;
					b[j]=x-max(a[i][1],a[i][2]);
				}
			}
			sort(b+1,b+j+1);
			for(i=1;i<=y;++i)z-=b[i];
		}
		cout<<z<<'\n';
	}
	return 0;
}
