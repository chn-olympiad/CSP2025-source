#include<bits/stdc++.h>
using namespace std;
struct node
{
	int m[4];
}a[100005];
int T,n,minn[1000005];
bool cmp(node x,node y)
{
	return x.m[1]>y.m[1];
}
bool cmmp(node x,node y)
{
	return x.m[2]>y.m[2];
}
bool cmmmp(node x,node y)
{
	return x.m[3]>y.m[3];
}
int f1(node x)
{
	return max(x.m[2],x.m[3]);
}
int f2(node x)
{
	return max(x.m[1],x.m[3]);
}
int f3(node x)
{
	return max(x.m[1],x.m[2]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		//memset(minn,0,sizeof(minn));
		long long ans=0;
		int js[4]={0,0,0,0};
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int maxx=-1,h;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i].m[j];
				if(maxx<a[i].m[j])
				{
					maxx=a[i].m[j];
					h=j;
				}
			}
			ans+=maxx;
			js[h]++;
		}
		for(int i=1;i<=3;i++)
		{
			if(js[i]>n/2)
			{
				if(i==1)
				{
					sort(a+1,a+1+n,cmp);
					int t=n/2,t1=n/2,t2=n/2,l=0;
					while(a[t1-1].m[i]==a[t1].m[i]) t1--;
					while(a[t2+1].m[i]==a[t2].m[i]) t2++;
					if(t1==t2) break;
					for(int j=t1;j<=t2;j++)
					{
						l++;
						minn[j]=a[j].m[i]-f1(a[j]);
					}
					sort(minn+t1,minn+l+t1);
					for(int j=t1;j<=t2-(t-t1);j++) ans-=minn[j];
				}
				if(i==2)
				{
					sort(a+1,a+1+n,cmmp);
					int t=n/2,t1=n/2,t2=n/2,l=0;
					while(a[t1-1].m[i]==a[t1].m[i]) t1--;
					while(a[t2+1].m[i]==a[t2].m[i]) t2++;
					if(t1==t2) break;
					for(int j=t1;j<=t2;j++)
					{
						l++;
						minn[j]=a[j].m[i]-f2(a[j]);
					}
					sort(minn+t1,minn+l+t1);
					for(int j=t1;j<=t2-(t-t1);j++) ans-=minn[j];
				}
				if(i==3)
				{
					sort(a+1,a+1+n,cmmmp);
					int t=n/2,t1=n/2,t2=n/2,l=0;
					while(a[t1-1].m[i]==a[t1].m[i]) t1--;
					while(a[t2+1].m[i]==a[t2].m[i]) t2++;
					if(t1==t2) break;
					for(int j=t1;j<=t2;j++)
					{
						l++;
						minn[j]=a[j].m[i]-f3(a[j]);
					}
					sort(minn+t1,minn+l+t1);
					for(int j=t1;j<=t2-(t-t1);j++) ans-=minn[j];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
