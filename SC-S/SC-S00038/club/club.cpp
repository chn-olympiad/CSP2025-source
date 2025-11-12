#include<bits/stdc++.h>
using namespace std;
long long n,m,T;
const int N=100000;
long long sum[4],ans;
struct o{
	int g[4],cha[3],maxx;
} a[N];
bool p(o x,o y)
{
	return x.cha[1]<y.cha[1];
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int k=1;k<=T;k++)
	{
		sum[1]=sum[2]=sum[3]=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int s=0;
			a[i].maxx=0;
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i].g[j]);
				if(a[i].g[j]>a[i].maxx)
				{
					a[i].maxx=a[i].g[j];
					s=j;
				}
			}
			sum[s]++;
			ans+=a[i].maxx;
			int lin=1;
			for(int j=1;j<=3;j++)
			{
				if(s!=j)
				a[i].cha[lin++]=a[i].maxx-a[i].g[j];
			}
			a[i].cha[1]=min(a[i].cha[1],a[i].cha[2]);
		}
		sort(a+1,a+n+1,p);
		if(sum[1]>n/2)
		{
			int j=1;
			while(sum[1]>n/2)
			{
				while(a[j].maxx!=a[j].g[1]) j++;
				ans-=a[j++].cha[1];
				sum[1]--;
			}
		}
		else if(sum[2]>n/2)
		{
			int j=1;
			while(sum[2]>n/2)
			{
				while(a[j].maxx!=a[j].g[2]) j++;
				ans-=a[j++].cha[1];
				sum[2]--;
			}
		}
		else if(sum[3]>n/2)
		{
			int j=1;
			while(sum[3]>n/2)
			{
				while(a[j].maxx!=a[j].g[3]) j++;
				ans-=a[j++].cha[1];
				sum[3]--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}