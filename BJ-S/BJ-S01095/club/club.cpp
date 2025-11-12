#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
ll a[100050][11];
ll f[4][100050],cnt[4],nw[100050],longs;
ll c[4][4]={{},{0,2,3},{0,1,3},{0,1,2}};
int n;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		//清除	
		for(int i=1;i<=3;i++)
			for(int j=1;j<=cnt[i];j++)
				f[i][j]=0;
		for(int i=1;i<=100049;i++)
			nw[i]=0;
		cnt[1]=cnt[2]=cnt[3]=0;		
		//清除板块
		//cout<<"acc"<<endl;
		ll mx,ans,p,hp,l[4]={};
		ans=0;	
		for(int i=1;i<=n;i++)
		{
			mx=0,p=0;
			for(int j=1;j<=3;j++)
			{
		
					cin>>a[i][j];
					if(a[i][j]>mx)
						mx=a[i][j],p=j;
			}	
		
			f[p][++cnt[p]]=i,l[p]++,ans+=mx;
		}
		//cout<<endl<<"L NUMB "<<l[1]<<' '<<l[2]<<' '<<l[3]<<endl;
		for(int k=1;k<=3;k++)
		{
			if(l[k]>n/2)
			{
				//差
				for(int i=1;i<=cnt[k];i++)
				{
					hp=f[k][i];
					nw[i]=min(a[hp][k]-a[hp][c[k][1]],a[hp][k]-a[hp][c[k][2]]);
					//cout<<" NW NUMB  "<<nw[i]<<' ';
				}
				//cout<<endl;
				sort(nw+1,nw+1+cnt[k]);
				for(int i=1;i<=l[k]-(n/2);i++)
					ans-=nw[i];
			}
		}
		cout<<ans<<endl;//<<"really?"<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
		return 0;
}
