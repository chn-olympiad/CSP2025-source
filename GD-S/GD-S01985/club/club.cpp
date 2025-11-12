#include<bits/stdc++.h>
#define ll long long
using namespace std;
int bm[10];
struct me
{
	int w[10],h[10];
	
}a[100010];
bool cmp(me aa,me b)
{
	return aa.w[4]>b.w[4];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int ma,mi,mm;
			cin>>ma>>mi>>mm;
			int z=max(ma,max(mi,mm)),nu;
			if(z==ma)nu=1;
			else if(z==mi)nu=2;
			else nu=3;
			a[i].w[1]=z;
			a[i].h[1]=nu;
			if(nu==1)z=max(mi,mm);
			else if(nu==2)z=max(ma,mm);
			else z=max(ma,mi);
			if(z==ma&&nu!=1)nu=1;
			else if(z==mi&&nu!=2)nu=2;
			else if(z==mm&&nu!=3)nu=3;
			a[i].w[2]=z;
			a[i].h[2]=nu;
			a[i].w[4]=a[i].w[1]-a[i].w[2];
			a[i].h[4]=a[i].h[1];
			a[i].h[5]=a[i].h[2];
		}
		sort(a+1,a+n+1,cmp);
		int k=n/2,ans=0; 
		bm[1]=bm[2]=bm[3]=0;
		for(int i=1;i<=n;i++)
		{
			int ha=a[i].h[4];
			if(bm[ha]<k)
			{
				bm[ha]++;
				ans+=a[i].w[1];
			}
			else
			{
				ha=a[i].h[5];
				bm[ha]++;
				ans+=a[i].w[2];
			}
			
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
	
	
	

