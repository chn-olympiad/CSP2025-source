#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][4],c1[100001],c2[100001],c3[100001],ans,ent[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		memset(c3,0,sizeof(c3));
		memset(ent,0,sizeof(ent));
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int maa=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=maa;
			int q=0;
			for(int j=1;j<=3;j++)
			{
				if(maa==a[i][j])
				{
					q=j;
					ent[j]++;
					break;
				}
			}
			if(q==1)c1[i]=2*maa-(a[i][1]+a[i][2]+a[i][3]-min(a[i][1],min(a[i][2],a[i][3])));
			if(q==2)c2[i]=2*maa-(a[i][1]+a[i][2]+a[i][3]-min(a[i][1],min(a[i][2],a[i][3])));
			if(q==3)c3[i]=2*maa-(a[i][1]+a[i][2]+a[i][3]-min(a[i][1],min(a[i][2],a[i][3])));
		}
		int mae=max(ent[1],max(ent[2],ent[3]));
		if(mae<=n/2)
		cout<<ans<<"\n";
		else
		{
			int p=0;
			for(int i=1;i<=3;i++)
			{
				if(mae==ent[i])
				p=i;
			}
			int b=ent[p]-n/2;
			if(p==1)sort(c1,c1+n);
			if(p==2)sort(c2,c2+n);
			if(p==3)sort(c3,c3+n);
			int l=0;
			while(b>0)
			{
				if(p==1)
				{
					if(c1[l]!=0)
					{
						b--;
						ans-=c1[l];
					}
				}
				if(p==2)
				{
					if(c2[l]!=0)
					{
						b--;
						ans-=c2[l];
					}
				}
				if(p==3)
				{
					if(c3[l]!=0)
					{
						b--;
						ans-=c3[l];
					}
				}
				l++;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
