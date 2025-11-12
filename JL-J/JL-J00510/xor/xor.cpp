#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,ans;
int a[N];
int x,y;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++){
    cin>>a[i];
   }
   for(int i=1;i<=n;i++){
        int l=a[i];
        if(l==m){
            ans++;
        }
        else{
            for(int j=i+1;j<=n;j++){
                l=l^a[j];
                if(l==m){
                    ans++;
                    y=x;
                    x=j;
                    break;
                }
         }
         if(x!=y){
            i=x;
         }
      }

   }
   cout<<ans<<endl;


    return 0;
}
