#include<bits/stdc++.h>
using namespace std;
struct ss1
{
	int id,p1,p2;
}e1[500007];
struct ss2
{
	int id,p1,p2;
}e2[500007];
bool px2(ss2 xx,ss2 yy)
{
	if(xx.p2==yy.p2)
	return xx.p1>yy.p1;
	return xx.p2<yy.p2;
}
bool px1(ss1 xx,ss1 yy)
{
	if(xx.p1==yy.p1)
	return xx.p2>yy.p2;
	return xx.p1<yy.p1;
}
int a[500007][4],n,a1[500007],mx[500007];

long long g[4]={0,0,0,0},w[4]={0,0,0,0},n2;
long long ma=0;

void dfs(int k)
{
	if(w[1]>n2||w[2]>n2||w[3]>n2)
	{
		return;
	}
	else if(k>n)
	{
//		cout<<g[1]+g[2]+g[3]<<endl;
		ma=max(ma,g[1]+g[2]+g[3]);
		return;
	}
	else
	{
		for(int i=1;i<=3;i++)
		{
			g[i]+=a[k][i];
			w[i]++;
			dfs(k+1);
			w[i]--;
			g[i]-=a[k][i];
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		g[1]=g[2]=g[3]=w[1]=w[2]=w[3]=ma=0;
		cin>>n;
		int ma1=0,ma2=0,ma3=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
//			e[i].p1=a[i][1];
//			e[i].p2=a[i][2];
//			e[i].id=i;
			a1[i]=a[i][1];
			ma1=max(ma1,a[i][1]);
			ma2=max(ma2,a[i][2]);
			ma3=max(ma3,a[i][3]);
			mx[i]=max(max(a[i][1],a[i][2]),a[i][3]);
		}
		n2=n/2;
		if(ma2==0&&ma3==0)
		{
			sort(a1+1,a1+1+n);
			long long sum=0;
			for(int i=n;i>n2;i--)
			{
				sum+=a1[i];
			}
			cout<<sum<<"\n";
		} 
		else if(n<=30)
		{
			dfs(1);
			cout<<ma<<"\n";
		}
		else if(ma3==0)
		{
			long long gw1=0,gw2=0,gw11=0,gw22=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i][1]>a[i][2])
				{
					gw11+=a[i][1];
					gw1++;
					e1[gw1].p1=a[i][1];
					e1[gw1].p2=a[i][2];
					e1[gw1].id=gw1;
					
				}
				else
				{
					gw22+=a[i][2];
					gw2++;
					e2[gw2].p1=a[i][1];
					e2[gw2].p2=a[i][2];
					e2[gw2].id=gw2;
				}
		
			}
//			cout<<gw11<<" "<<gw22<<endl;
			if(gw2>gw1)		
			{
				sort(e2+1,e2+1+gw2,px2);
				for(int i=1;i<(gw2-gw1)/2;i++)
				{
					gw22-=e2[i].p2;
					gw11+=e2[i].p1;
				}
				cout<<gw11+gw22<<"\n";
			}
			
			else		
			{
				sort(e1+1,e1+1+gw1,px1);
				for(int i=1;i<(gw1-gw2)/2;i++)
				{
					gw11-=e1[i].p1;
					gw22+=e1[i].p2;
				}
				cout<<gw11+gw22<<"\n";
			}		
		}
		else //if(!(ma2==0||ma3==0))
		{
			long long sum=0;
			for(int i=1;i<=n;i++)
			{
				sum+=mx[i];
				
			}
			cout<<sum<<"\n";
		}
	}
	return 0;
}
