#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,a[500005],f[500005],s[1<<22],t,k;
signed main()
{
	//ccf is "good"
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout); 
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   cin>>n>>k;
   for(int i=1;i<=n;i++)cin>>a[i];
   memset(s,-1,sizeof(s));
   s[0]=0;
   for(int i=1;i<=n;i++)
   {
   	   t=t^a[i];
   	   f[i]=max(f[i-1],f[i]); 
   	   int u=s[k^t];
	   s[t]=i;
   	   if(u==-1)continue;
   	   f[i]=max(f[i],f[u]+1);
   }
   cout<<f[n];
  return 0;
}
