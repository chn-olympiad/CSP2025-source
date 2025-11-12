#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=5e5+5;
int a[N];
signed main(){
     freopen("xor.in","r",stdin);
     freopen("xor.out","w",stdout);
     int n,k;
     cin>>n>>k;
     for(int i=1;i<=n;i++){
         cin>>a[i];
     }
     int ans=0;
     for(int i=1;i<=n;i++){
         if(a[i]==k){
            ans++;
            continue;
         }
         for(int j=i+1;j<=n;j++){
             int rs=a[i];
             for(int l=i+1,r=j;l<=j;l++){
                 rs=rs^a[l];
             }
             if(rs==k){
                ans++;
                i=j;
                break;
             }

         }
     }
     cout<<ans;
     fclose(stdin);
     fclose(stdout);
     return 0;
}
