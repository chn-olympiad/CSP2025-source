#include<bits/stdc++.h>
using namespace std;
int t,n;
int y[10];
struct o
{
	int a1,b2,c3;
	int ma;
	int maxn;
	int mac;
	int sec;
}a[100005];
bool cmp(o l1,o l2)
{
	return l1.mac>l2.mac;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		y[1]=0;
		y[2]=0;
		y[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].b2>>a[i].c3;
			a[i].ma=max(a[i].a1,max(a[i].b2,a[i].c3));
			if(a[i].ma==a[i].a1) 
			{
				a[i].maxn=1;
				if(a[i].b2>=a[i].c3) a[i].sec=a[i].b2;
				else a[i].sec=a[i].c3;
			}
			else if(a[i].ma==a[i].b2) 
			{
				a[i].maxn=2;
				if(a[i].a1>=a[i].c3) a[i].sec=a[i].a1;
				else a[i].sec=a[i].c3;
			}
			else 
			{
				a[i].maxn=3;
				if(a[i].b2>=a[i].a1) a[i].sec=a[i].b2;
				else a[i].sec=a[i].a1;
			}
			a[i].mac=a[i].ma-a[i].sec;
		}
		int k=n/2,ans=0;		
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			int liu=a[i].maxn;
			if(y[liu]<k) 
			{
				y[liu]++;
				ans+=a[i].ma;
			}
			else
			{
				for(int j=i;j<=n;j++)
				{
					if(a[j].maxn!=liu) continue;
					a[j].ma=a[j].sec; 
					if(liu==1)
					{
						if(a[j].sec==a[j].b2) a[j].maxn=2;
						else a[j].maxn=3;
						a[j].mac=abs(a[j].b2-a[j].c3); 	
					}
					else if(liu==2)
					{
						if(a[j].sec==a[j].a1) a[j].maxn=1;
						else a[j].maxn=3;
						a[j].mac=abs(a[j].a1-a[j].c3); 	
					}
					else
					{
						if(a[j].sec==a[j].b2) a[j].maxn=2;
						else a[j].maxn=1;
						a[j].mac=abs(a[j].b2-a[j].a1); 	
					}
				}
				sort(a+i,a+n+1,cmp);
				i--;
			} 
		}
		cout<<ans<<endl;
	}
	return 0;
} 