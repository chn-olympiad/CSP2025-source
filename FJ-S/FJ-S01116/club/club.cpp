#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,m[100100];
struct node{
	int x1;
	int x2;
	int x3;
}a[100100];
int ch[100100];
long long dow[100100];
int k[5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--)
	{
	  k[1]=k[2]=k[3]=0;ans=0;
	  memset(dow,0,sizeof dow);
	  memset(a,0,sizeof a);
	  cin>>n;
	  for(int i=1;i<=n;i++)
	    cin>>a[i].x1>>a[i].x2>>a[i].x3;
	  for(int i=1;i<=n;i++)
	    if(a[i].x1>=a[i].x2 && a[i].x1>=a[i].x3)
	      ch[i]=1,ans+=a[i].x1,k[1]++;
	    else if(a[i].x2>=a[i].x1 && a[i].x2>=a[i].x3)
	      ch[i]=2,ans+=a[i].x2,k[2]++;
	    else
	      ch[i]=3,ans+=a[i].x3,k[3]++;
	  if(k[1]<=(n>>1)&&k[2]<=(n>>1)&&k[3]<=(n>>1)) {cout<<ans<<'\n';continue;}
	  if(k[1]>(n>>1))
	  {
	  	for(int i=1;i<=n;i++)
	  	  if(ch[i]==1)
	  	    dow[++dow[0]]=min(a[i].x1-a[i].x2,a[i].x1-a[i].x3);
	  	sort(dow+1,dow+1+dow[0]);
	  	for(int i=1;i<=k[1]-(n>>1);i++)
	  	  ans-=dow[i];
	  	cout<<ans<<'\n';
	  }
	  
	  if(k[2]>(n>>1))
	  {
	  	for(int i=1;i<=n;i++)
	  	  if(ch[i]==2)
	  	    dow[++dow[0]]=min(a[i].x2-a[i].x1,a[i].x2-a[i].x3);
	  	sort(dow+1,dow+1+dow[0]);
	  	for(int i=1;i<=k[2]-(n>>1);i++)
	  	  ans-=dow[i];
	  	cout<<ans<<'\n';
	  }
	  
	  if(k[3]>(n>>1))
	  {
	  	for(int i=1;i<=n;i++)
	  	  if(ch[i]==3)
	  	    dow[++dow[0]]=min(a[i].x3-a[i].x2,a[i].x3-a[i].x1);
	  	sort(dow+1,dow+1+dow[0]);
	  	for(int i=1;i<=k[3]-(n>>1);i++)
	  	  ans-=dow[i];
	  	cout<<ans<<'\n';
	  }
	}
	return 0;
}