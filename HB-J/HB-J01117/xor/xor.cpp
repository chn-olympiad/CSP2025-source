#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],sum[N],num[20005][20005];
struct Node{
  int beginn,endd;
}q[N];
bool cmp(Node x,Node y){
  return x.endd<y.endd;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
   cin>>n>>k;
   cin>>a[1];
   sum[1]=a[1];
   for(int i=2;i<=n;i++){
    cin>>a[i];
    sum[i]=(sum[i-1]^a[i]);
   }
   // cout<<(1^3);
   long long top=0;
   for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){
        if((sum[j]^sum[i-1])==k){ //find
            top++;
            q[top].beginn=i;
            q[top].endd=j;
        }
     }
   }
   sort(q+1,q+1+top,cmp);
   long long tot=-1,ans=0;
   for(int i=1;i<=top;i++){
       if(q[i].beginn>tot)
         ans++,tot=q[i].endd;
   }
   cout<<ans;
    return 0;
}
