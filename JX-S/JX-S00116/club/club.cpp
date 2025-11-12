#include<bits/stdc++.h>
using namespace std;
int a[100010][5],s[5],p[5];
int w12[100010],w23[100010],w13[100010],w21[100010],w31[100010],w32[100010];
int m[100010],v[100010],d[100010];
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
   int t;
   cin>>t;
   for(int i=1;i<=t;i++)
   {
	  for(int j=1;j<=3;j++){s[j]=0;p[j]=0;}
	  int n;
	  long long int ans=0;
	  cin>>n;
	  int f=0,g=0,h=0;
	  for(int j=1;j<=n;j++)
	  {
		 cin>>a[j][1]>>a[j][2]>>a[j][3];
		 int k=max(max(a[j][1],a[j][2]),a[j][3]);
		 ans=ans+k;
		      if(k==a[j][1]){f++;p[1]++;w12[f]=a[j][1]-a[j][2];w13[f]=a[j][1]-a[j][3];m[f]=min(w12[f],w13[f]);}
		 else if(k==a[j][2]){g++;p[2]++;w23[g]=a[j][2]-a[j][3];w21[g]=a[j][2]-a[j][1];v[g]=min(w21[g],w23[g]);}
		 else if(k==a[j][3]){h++;p[3]++;w32[h]=a[j][3]-a[j][2];w31[h]=a[j][3]-a[j][1];d[h]=min(w31[h],w32[h]);}
	  }
	  
	  
	  if(p[1]*2>n)
	  {
		  sort(m+1,m+f+1);
		  int l=p[1]-n/2;
		  for(int i=1;i<=l;i++)
		  {
			  ans=ans-m[i];
		  }
	  }
	  
	  
	  else if(p[2]*2>n)
	  {
		  sort(v+1,v+g+1);
		  int l=p[2]-n/2;
		  for(int i=1;i<=l;i++)
		  {
			  ans=ans-v[i];
		  }
	  }
	  
	  
	  else if(p[3]*2>n)
	  {
		  sort(d+1,d+h+1);
		  int l=p[3]-n/2;
		  for(int i=1;i<=l;i++)
		  {
			  ans=ans-d[i];
		  }
	  }
	  
	  cout<<ans<<endl;
	  for(int j=1;j<=n;j++)
	  {
		 w21[j]=0;
		 w31[j]=0;
		 w32[j]=0;
		 w12[j]=0;
		 w23[j]=0;
		 w13[j]=0;
		 m[j]=0;
		 v[j]=0;
		 d[j]=0;
	  }
   }
      
   return 0;
}
