#include<bits/stdc++.h>
#define int long long 
using namespace std;
struct nide{
	int ai;
	int bi;
	int ci;
	int mx;
	int mn;
	int md;
};

nide a[100010];
int vis[100010];
bool cmp(nide x,nide y)
{
	return (x.mx-x.mn)>(y.mx-y.mn);
}
int fn(int i,int k)
{
	int l=0;
	if(k==1) l=a[i].mx;
	else if(k==2) l=a[i].md;
	else l=a[i].mx; 
	if(l==a[i].ai) return 1;
	else if(l==a[i].bi) return 2;
	else return 3;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int am=0;
		int bm=0;
		int cm=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].ai>>a[i].bi>>a[i].ci;
			a[i].mx=max(a[i].ai,max(a[i].bi,a[i].ci));
			a[i].mn=min(a[i].ai,min(a[i].bi,a[i].ci));
			a[i].md=(a[i].ai+a[i].bi+a[i].ci)-a[i].mx-a[i].mn;	
			vis[i]=0;
		}
		sort(a+1,a+1+n,cmp);
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			int imxl=fn(i,1);
			int imdl=fn(i,2);
			int imnl=fn(i,3);
			if(imxl==1)
			{
				if(am+1<=n/2)
				{
					am++;
					sum+=a[i].mx;	
				}
				else if(am+1>n/2)
				{
					if(imdl==2)
					{
						if(bm+1<=n/2)
						{
							bm++;
							sum+=a[i].md;
						}
						else if(bm+1>n/2)
						{
							cm++;
							sum+=a[i].mn;
						}
					}
					else if(imdl==3)
					{
						if(cm+1<=n/2)
						{
							cm++;
							sum+=a[i].md;
						}
						else if(cm+1>n/2)
						{
							bm++;
							sum+=a[i].mn;
						}
					}
				}
			}
			if(imxl==2)
			{
				if(bm+1<=n/2)
				{
					bm++;
					sum+=a[i].mx;	
				}
				else if(am+1>n/2)
				{
					if(imdl==1)
					{
						if(am+1<=n/2)
						{
							am++;
							sum+=a[i].md;
						}
						else if(am+1>n/2)
						{
							cm++;
							sum+=a[i].mn;
						}
					}
					else if(imdl==3)
					{
						if(cm+1<=n/2)
						{
							cm++;
							sum+=a[i].md;
						}
						else if(cm+1>n/2)
						{
							am++;
							sum+=a[i].mn;
						}
					}
				}
			}
			if(imxl==3)
			{
				if(cm+1<=n/2)
				{
					cm++;
					sum+=a[i].mx;	
				}
				else if(cm+1>n/2)
				{
					if(imdl==1)
					{
						if(am+1<=n/2)
						{
							am++;
							sum+=a[i].md;
						}
						else if(am+1>n/2)
						{
							bm++;
							sum+=a[i].mn;
						}
					}
					else if(imdl==2)
					{
						if(bm+1<=n/2)
						{
							bm++;
							sum+=a[i].md;
						}
						else if(bm+1>n/2)
						{
							am++;
							sum+=a[i].mn;
						}
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

