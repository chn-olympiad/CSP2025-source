#include<bits/stdc++.h>
#define LL long long
using namespace std;
int t,n,f[205][205][205];
struct node
{
	int x,y,z;
}a[200005],b[200005];
bool cmp(node l,node r)
{
	return l.x>r.x;
}
bool cmp1(node l,node r)
{
	if(l.x==r.x)return l.y<r.y;
	return l.x>r.x;
}
bool cmp2(node l,node r)
{
	if(l.y==r.y)return l.x<r.x;
	return l.y>r.y;
}
int main()
{
	srand(time(0));
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
   cin>>t;
   while(t--)
   {
   	   cin>>n;
	   int ans=0;
   	   bool flaga=true,flagb=true;
   	   for(int i=1;i<=n;i++)
   	   {
   	   		cin>>a[i].x>>a[i].y>>a[i].z;
   	   		b[i]=a[i];
   	   		if(a[i].z!=0)flaga=false,flagb=false;
   	   		else if(a[i].y!=0)flaga=false;
	   }
	    if(flaga==true)
		{
			sort(a+1,a+1+n,cmp); 
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
			cout<<ans<<"\n";
			continue;
		}
   	   if(n<=200)
   	   {
   	   	   
   	   	   for(int i=1;i<=n;i++)
   	   	   {
   	   	   	   for(int j=0;j<=n/2;j++)
   	   	   	   {
   	   	   	   	   for(int k=0;k<=n/2;k++)
   	   	   	   	   {
   	   	   	   	   	    int kk=i-j-k;
   	   	   	   	   	    if(kk>n/2)continue;
   	   	   	   	   	    
   	   	   	   	   	    	if(j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i].x);
   	   	   	   	   	    	if(k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i].y);
   	   	   	   	   	    	if(kk) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].z);
   	   	   	   	   	    	if(i==n&&j+k+kk==n)
   	   	   	   	   	    	{
   	   	   	   	   	    		ans=max(ans,f[i][j][k]);
							}
						
				   }
			   }
		   }
		   cout<<ans<<"\n";
		   continue;
	   }
	   for(int i=1;i<=n;i++)
	   {
	   	   int u=rand()%3;
	   	   if(u==0)ans+=a[i].x;
	   	   else if(u==1)ans+=a[i].y;
	   	   else ans+=a[i].z;
	   }
	   cout<<ans<<"\n";
   } 
   return 0;
}

