#include<bits/stdc++.h>
using namespace std;
int T,n,a[100001][4];
long long ans;
int f1(int w)
{
	if(a[w][1]>=a[w][2] and a[w][1]>=a[w][3])return 1;
	if(a[w][2]>=a[w][1] and a[w][2]>=a[w][3])return 2;
	if(a[w][3]>=a[w][1] and a[w][3]>=a[w][2])return 3;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
		ans=0;
		int o[4]={0,0,0,0};
		cin>>n;
		int p=n/2;
		for(int j=1;j<=n;j++)
		  for(int k=1;k<=3;k++)
		    scanf("%d",&a[j][k]);
		for(int j=1;j<=n;j++)
			o[f1(j)]++,ans+=a[j][f1(j)];
		while(o[1]>p or o[2]>p or o[3]>p)
		{
			if(o[1]>p)
			{
				int minn=INT_MAX,min1;
				for(int k=1;k<=n;k++)
				  if(f1(k)==1)
				  {
					int tmp=a[k][1]-max(a[k][2],a[k][3]);
				    if(tmp<=minn and a[k][2]>=a[k][3])minn=tmp,min1=2;
				    if(tmp<=minn and a[k][2]<a[k][3])minn=tmp,min1=3;
				  }
				if(minn==INT_MAX)minn=0;
				o[1]--,o[min1]++,ans-=minn;
			}
			if(o[2]>p)
			{
				int minn=INT_MAX,min1;
				for(int k=1;k<=n;k++)
				  if(f1(k)==2)
				  {
					int tmp=a[k][2]-max(a[k][1],a[k][3]);
				    if(tmp<=minn and a[k][1]>=a[k][3])minn=tmp,min1=1;
				    if(tmp<=minn and a[k][1]<a[k][3])minn=tmp,min1=3;
				  }
				if(minn==INT_MAX)minn=0;
				o[2]--,o[min1]++,ans-=minn;
			}
			if(o[3]>p)
			{
				int minn=INT_MAX,min1;
				for(int k=1;k<=n;k++)
				  if(f1(k)==3)
				  {
					int tmp=a[k][3]-max(a[k][1],a[k][2]);
				    if(tmp<=minn and a[k][1]>=a[k][2])minn=tmp,min1=1;
				    if(tmp<=minn and a[k][1]<a[k][2])minn=tmp,min1=2;
				  }
				if(minn==INT_MAX)minn=0;
				o[3]--,o[min1]++,ans-=minn;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}

