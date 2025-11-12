#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
long long t,n,ans,f[100001][4];
struct date
{
	long long a[4],max1,max2,max3;
}k[100001];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		cin>>n;
		ans=0;
		f[1][0]=f[2][0]=f[3][0]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>k[i].a[1]>>k[i].a[2]>>k[i].a[3];
			k[i].max1=1;k[i].max2=2;k[i].max3=3;
			if(k[i].a[k[i].max1]<k[i].a[k[i].max2]) swap(k[i].max1,k[i].max2);
			if(k[i].a[k[i].max2]<k[i].a[k[i].max3]) swap(k[i].max2,k[i].max3);
			if(k[i].a[k[i].max1]<k[i].a[k[i].max2]) swap(k[i].max1,k[i].max2);
			if(f[k[i].max1][0]==n/2)
			{
				long long x=0,y=k[i].a[k[i].max1]-k[i].a[k[i].max2];
				for(int j=1;j<=f[k[i].max1][0];j++)
				{
					long long s=f[k[i].max1][j];
					if(y>k[j].a[k[s].max1]-k[j].a[k[s].max2])
					{
						y=k[j].a[k[s].max1]-k[j].a[k[s].max2];
						x=j;
					}}
				if(x==0){
					f[k[i].max2][0]++;
					f[k[i].max2][f[k[i].max2][0]]=i;
					ans+=k[i].a[k[i].max2];}
				else{
					ans-=k[x].a[k[x].max1];
					ans+=k[i].a[k[i].max1];
					ans+=k[x].a[k[x].max2];
					f[k[i].max1][x]=i;
					f[k[x].max2][0]++;
					f[k[x].max2][f[k[x].max2][0]]=x;
					}
			}
			else{
				f[k[i].max1][0]++;
				f[k[i].max1][f[k[i].max1][0]]=i;
				ans=ans+k[i].a[k[i].max1];
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}
			
			
