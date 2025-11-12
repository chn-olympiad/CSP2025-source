#include <bits/stdc++.h>
using namespace std;
int mod=998244353;
bool can(int a,int b,int c){
      if(a+b<c && a+c<b && b+c<a){
            return true;
      }
      return false;
}
int main(){
      //freopen("polygon.in","r",stdin);
      //freopen("polygon.out","w",stdout);
      int n,cnt=0;
      scanf("%d",&n);
      vector<int>timb;

      for(int i=0;i<n;i++){
            scanf("%d",&timb[i]);
      }
      for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                  for(int k=2;k<n;k++){

                        if(can(timb[i],timb[j],timb[k])){
                              cnt=(cnt+1)%mod;
                        }
                  }
            }
      }
      printf("%d",cnt%mod);
      return 0;
}
