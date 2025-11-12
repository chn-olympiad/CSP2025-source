#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,z[4],y;
long long z1[100005],z2[100005],z3[100005];
struct pp
{
	int v,d;
}v[4];
bool arm(pp a,pp b)
{
	return a.v<b.v;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
     cin>>t;
     for(int w=1;w<=t;w++)
     {
		 ans=0; y=0;
		 z[1]=0;z[2]=0;z[3]=0;
		 cin>>n;
		 for(int i=1;i<=n;i++)
		 {
             for(int j=1;j<=3;j++)
             {
				 cin>>v[j].v;
				 v[j].d=j;
				 
			 }
			 sort(v+1,v+4,arm);
			
			 ans+=v[3].v;
			 z[v[3].d]++;   
			 if(v[3].d==1) z1[z[v[3].d]]=v[3].v-v[2].v;
			 else if(v[3].d==2) z2[z[v[3].d]]=v[3].v-v[2].v;
			 else if(v[3].d==3) z3[z[v[3].d]]=v[3].v-v[2].v;
		 }
	
		 int d=0;
		 for(int i=1;i<=3;i++)
		 {
			 if(z[i]>n/2)
			 {
				  d=i;
				  y=z[i]-(n/2);
			 }
		 }
		 if(d==1) sort(z1+1,z1+1+z[d]);
	   	 else if(d==2) sort(z2+1,z2+1+z[d]);
		 else if(d==3) sort(z3+1,z3+1+z[d]);
		
		 if(y>0&&d==1) for(int i=1;i<=y;i++) ans-=z1[i];  
		 else if(y>0&&d==2) for(int i=1;i<=y;i++) ans-=z2[i];
		 else if(y>0&&d==3) for(int i=1;i<=y;i++) ans-=z3[i];
		 cout<<ans<<endl;
     }
   return 0;
}
