#include <bits/stdc++.h>
using namespace std;
int n,t,a[100005],b[100005],c[100005],d[10],e[100],p[100];
int cnt=0,m=0;
long long ans=0;
int main()
{
 freopen("club.in","r",stdin);
 freopen("club.out","w",stdout);
 cin>>t>>n;
 while(t--){
	 ans=0;
 for(int i=1;i<=n;i++)
 cin>>a[i]>>b[i]>>c[i];
 if(n==2){ 
 for(int i=1;i<=n;i++){
	  p[i]=max(a[i],b[i]);
    d[i]=max(p[i],c[i]);
    if(d[i]==a[i]) e[i]=1;
    else if(d[i]==b[i]) e[i]=2;
    else if(d[i]==c[i]) e[i]=3;
    }
    
   if(e[1]==e[2]) {
   if(d[1]>d[2]) {
     ans+=d[1];
     if(e[2]==1) ans+=max(b[2],c[2]);
     else if(e[2]==2) ans+=max(a[2],c[2]);
     else if(e[2]==3) ans+=max(a[2],b[2]); 
     }
      else if(d[2]>d[1]) {
     ans+=d[2];
     if(e[1]==1) ans+=max(b[1],c[1]);
     else if(e[1]==2) ans+=max(a[1],c[1]);
     else if(e[1]==3) ans+=max(a[1],b[1]); 
     }
    else if(d[1]==d[2])
     {
	  int stu[5]=0;
	  stu[1]=max(b[1],b[2]);
	  stu[2]=max(c[1],c[2]);
	  stu[3]=max(a[1],a[2]);
     ans+=d[1];
     if(e[1]==1) ans+=max(stu[1],stu[2]);
     else if(e[1]==2) ans+=max(stu[3],stu[2]);
     else if(e[1]==3) ans+=max(stu[3],stu[1]); 
   
   
  }
  }
   else ans=d[1]+d[2];
   cout<<ans<<endl;
}
  
  
  for(int i=1;i<=n;i++)
   if(b[i]==0&&c[i]==0)
    cnt++;  
   if(cnt==n){ 
   sort(a+1,a+n+1);
   for(int i=n;i>n/2;i--)
   ans+=a[i],m++;
   if(m=n/2);
   cout<<ans<<endl;
   }
}
    return 0;
}
