#include<bits/stdc++.h>
using namespace std;
long long dp[111][111];//前i个加入j个号俱乐部的最大值
long long fla1,fla2;
struct node{
	
	long long n1,n2,n3,bi;
}a[200000];
bool cmp1(node a,node b){
	return a.n1>b.n1;
}
bool cmp2(node a,node b){
	return a.n2>b.n2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
    cin>>t;
    while(t--){
	fla1=1,fla2=1;
      long long n;
      cin>>n;
      for(long long i=1;i<=n;i++){
         cin>>a[i].n1>>a[i].n2>>a[i].n3;
         	  if(a[i].n3!=0||a[i].n2!=0)fla2=0;
         a[i].bi=i;
      }
      if(fla2==1){
		  sort(a+1,a+1+n,cmp1);
		  long long ans1=0;
		  for(long long i=1;i<=n/2;i++){
			  ans1+=a[i].n1;
		  }
		  cout<<ans1<<endl;
	  }else{
		  long long ans=0;
      for(long long i=0;i<=100;i++){
		  for(long long j=0;j<=100;j++){
			  dp[i][j]=0;
		  }
	  }
      for(long long i=1;i<=n;i++){
          for(long long j=min(i,n/2);j>=0;j--){
             for(long long k=min(i-j,n/2);k>=0;k--){
             long long e=i-j-k;
             if(e>n/2)continue;
             long long a1=0,a2=0,a3=0;
             if(j!=0)a1=dp[j-1][k]+a[i].n1;
             if(k!=0)a2=dp[j][k-1]+a[i].n2;
             if(k+j!=i)a3=dp[j][k]+a[i].n3;
             dp[j][k]=max(a1,max(a2,a3));
          //   cout<<i<<" "<<j<<" "<<k<<" "<<dp[j][k]<<endl;
             ans=max(ans,dp[j][k]);
             }         
          }
      }		
      cout<<ans<<endl;  
	  } 
      
    }
   return 0;
}
//10000 8888
//10000 8888
//8888 1
//8888 1
