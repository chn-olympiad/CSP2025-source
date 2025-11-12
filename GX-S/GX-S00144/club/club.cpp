#include<bits/stdc++.h>
using namespace std;
int mac(int a,int b)
{
	if(a>=b) return a;
	else return b;
}
int br2(int a,int b,int c,int d,int e,int f)
{
	int hf=mac(c+d,c+e);
	int hg=mac(b+d,mac(b+f,hf));
	int hi=mac(a+e,mac(a+f,hg));
	return hi;
}
bool hbr(int a,int b,int c,int d)
{
	if((a==b&&b==c)||(a==b&&b==d)||(a==c&&c==d)||(b==c&&c==d)) return 1;
	else return 0;
}
int i2(int m,int n,int q,int p,int e,int f,int g,int h,int i,int j,int k,int l)
{
	int z[54],z1=0;
	int a[3]={m,n,q};
	int b[3]={p,e,f};
	int c[3]={g,h,i};
	int d[3]={j,k,l};
	for(int i=0;i<3;i++)
	{
		int y=i;
		for(int i=0;i<3;i++)
		{ 
			int y1=i;
			for(int i=0;i<3;i++)
			{
				int y2=i;
				if(y==y1&&y1==y2) continue;
				else
				for(int i=0;i<3;i++)
				{
					int y3=i;
					if(hbr(y,y1,y2,y3)) continue;
					else 
					{
						z[z1]=a[y]+b[y1]+c[y2]+d[y3];
						z1++;
					}
				}
			}
		}
	}
	int ans=-1000;
	for(int i=0;i<54;i++)
	{
		if(z[i]>ans)
		{
			ans=z[i];
		}
	}
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		int a[n],b[n],c[n],ans;
		for(int j=0;j<n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
		}
		if(n==2)
		{
			ans=br2(a[0],b[0],c[0],a[1],b[1],c[1]);
		}
		else if(n==4)
		{
			ans=i2(a[0],b[0],c[0],a[1],b[1],c[1],a[2],b[2],c[2],a[3],b[3],c[3]);
		}
		else
		{
			sort(a,a+n);
			ans=0;
			for(int i=n-1;i>n-1-(n/2);i--)
			{
				ans+=a[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
